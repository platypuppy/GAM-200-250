#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <string>
#include <fstream>
#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"
#include <vector>

//#include "DeSerializable.h"
#include "DSObject.h"

// Object DeSerializer Functions
namespace ObjectSerializer {
  //prototypes
  static void createMember(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& member);
  static std::vector<std::any>* makeArray(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value);
  
  /*********************************************************************/
  /*
   Function: JSONError
Description: Prints out json error if there is an error
     Inputs: ok   - the result of parsing the json file
             path - the path to the file that was parsed
    Outputs: N/A
   */
  /*********************************************************************/
  static void JSONError(rapidjson::ParseResult ok, const char * path) {
    // check if an error occurred
    if (!ok)
      // if an error occurred then print out formatted error message
      std::cerr << path
                << ":"
                << ok.Offset()
                << ": "
                // retrive error message from rapidjson
                << rapidjson::GetParseError_En(ok.Code())
                << std::endl;
  }

  /*********************************************************************/
  /*
   Function: JSONMemberError
Description: Prints out a formatted error
     Inputs: path        - path to the file that the error occured in
             key         - the name of the member with an error
             errorString - desccription of the error
    Outputs: N/A
   */
  /*********************************************************************/
  static void JSONMemberError(const char *path, const std::string& key, const char *errorString) {
    // print out a formatted error message 
    std::cerr << path
              << ":\""
              << key
              << "\": "
              << errorString
              << std::endl;
  }

  /*********************************************************************/
  /*
   Function: createObject
Description: create a new object with the contents stored in |value|
     Inputs: path    - path to the file that the object is currently in
             objects - vector containing all the objects created
             obj     - the object we are currently using
             name    - name of hte object
             value   - the contents of the object
    Outputs: a pointer to the object that was just created
   */
  /*********************************************************************/
  static DeSerializable* createObject(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value) {
    // print out a  message if the name of the object is "object"
    if (name == "object")
      std::cout << "its an object!";

    // create a new object with nothing inside of it
    DeSerializable* object = DSObject::NewObject();

    // add the object to the end of the vector
    objects->push_back(object);


    // add the new object as a child to the current object
    obj->AddComponent("child", std::make_any<DeSerializable*>(object));

    // add the current object as the parent to the new object
    object->AddComponent("parent", std::make_any<DeSerializable*>(obj));


    // loop through all of the members of the object and add the members
    for (auto it = value.MemberBegin(); it != value.MemberEnd(); ++it)
      createMember(path, objects, object, it->name.GetString(), it->value);
    
    return object;
  }

  
  /*********************************************************************/
  /*
   Function: addValue
Description: creates the member and adds the value to the object
     Inputs: path    - path to the file that the object is currently in
             objects - vector containing all the objects created
             obj     - the object to add the value to
             name    - the name of the member
             value   - the contents of the member
    Outputs: N/A
   */
  /*********************************************************************/
  static void addValue(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value) {
    // switch on the type of |value|
    switch (value.GetType()) {

      // NULL types will not be read
      case rapidjson::Type::kNullType:
        JSONMemberError(path, name, " warning: |kNullType| will not be read");
        break;

      // Add Boolean Types
      case rapidjson::Type::kFalseType:
      case rapidjson::Type::kTrueType:
        if (!obj->AddComponent(name, std::make_any<bool>(value.GetBool())))
          JSONMemberError(path, name, " error: unsupported key");
        break;
        
      // create object and that will add itself as a child to the current object
      case rapidjson::Type::kObjectType:
        createObject(path, objects, obj, name, value);
        break;
        
      // create an array and add it to the object
      case rapidjson::Type::kArrayType:
        if (!obj->AddComponent(name, std::make_any<std::vector<std::any>*>(makeArray(path, objects, obj, name, value))))
          JSONMemberError(path, name, " error: unsupported key");
        break;
        
      // add the string to the object
      case rapidjson::Type::kStringType:
        if (!obj->AddComponent(name, std::make_any<std::string>(value.GetString())))
          JSONMemberError(path, name, " error: unsupported key");
        break;
        
      // check what type of number it is then add it
      case rapidjson::Type::kNumberType:
        // check if |value| is an int
        if (value.IsInt()) {
          if (!obj->AddComponent(name, std::make_any<int>(value.GetInt())))
            JSONMemberError(path, name, " error: unsupported key");

        // check if |value| is a double
        } else if (value.IsDouble()) {
          if (!obj->AddComponent(name, std::make_any<double>(value.GetDouble())))
            JSONMemberError(path, name, " error: unsupported key");
          
        // this should never occur, give error if it is a number but not one of the supported types
        } else
          JSONMemberError(path, name, " error: unsupported number type");
        break;
        
      // also should not occur, give error if the type is not found
      default:
        JSONMemberError(path, name, " error: unsupported type");
        break;
    }
  }

  /*********************************************************************/
  /*
   Function: makeArray
Description: create and return an array
     Inputs: path    - path to the file we are parsing
             objects - vector with all th objects created
             obj     - the current object that we are appending to
             name    - name of the array
             value   - the contents of the array
    Outputs: vector of members
   */
  /*********************************************************************/
  static std::vector<std::any>* makeArray(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value) {
    // create an array to return
    std::vector<std::any>* array = new std::vector<std::any>;

    // initialize the current value of the array to NULL as default
    rapidjson::Type currentArrayType = rapidjson::Type::kNullType;
    
    // if the type is a number keep track of what type of number it is
    bool isInt = false;

    // loop through all of the values int he array and add them to the end of the vector
    for (rapidjson::SizeType i = 0; i < value.Size(); ++i) {
      // check if the type is correct then store it
      switch(value[i].GetType()) {
        // NULL types in arrays are not supported
        case rapidjson::Type::kNullType:
          JSONMemberError(path, name, " error: unsupported array type");
          break;
          
        // attempt to add a bollean to the array
        case rapidjson::Type::kFalseType:
        case rapidjson::Type::kTrueType:
          // set the type of the contents of the array
          if (currentArrayType == rapidjson::Type::kNullType)
            currentArrayType = value[i].GetType();

          // check if the type is what we expect it to be
          if (currentArrayType == value[i].GetType())
            array->push_back(std::make_any<bool>(value[i].GetBool()));
          // we do not support heterogeneous arrays
          else
            JSONMemberError(path, name, " error: heterogeneous arrays not supported");
          break;
          
        // attempt to add an object to the end of the array
        case rapidjson::Type::kObjectType:
          // set the type of the array
          if (currentArrayType == rapidjson::Type::kNullType)
            currentArrayType = value[i].GetType();

          // check if the type is what we expect it to be
          if (currentArrayType == value[i].GetType())
            array->push_back(std::make_any<DeSerializable*>(createObject(path, objects, obj, name, value[i])));
          // we do not support heterogeneous arrays
          else
            JSONMemberError(path, name, " error: heterogeneous arrays not supported");
          break;
          
        // attempt to add an array to the end of the array
        case rapidjson::Type::kArrayType:
          // set the type of the array to be array
          if (currentArrayType == rapidjson::Type::kNullType)
            currentArrayType = value[i].GetType();

          // check if the type is what we expect
          if (currentArrayType == value[i].GetType())
            array->push_back(std::make_any<std::vector<std::any>*>(makeArray(path, objects, obj, name, value[i])));
          // we do not accept heterogeneous arrays
          else
            JSONMemberError(path, name, " error: heterogeneous arrays not supported");
          break;
          
        // attempt to add a string to the end of the array
        case rapidjson::Type::kStringType:
          // set the type of the array to be String
          if (currentArrayType == rapidjson::Type::kNullType)
            currentArrayType = value[i].GetType();

          // check if the type is what we expect
          if (currentArrayType == value[i].GetType())
            array->push_back(std::make_any<std::string>(value[i].GetString()));
          // we do not accept heterogeneous arrays
          else
            JSONMemberError(path, name, " error: heterogeneous arrays not supported");
          break;
          
        // attempt to add a number to the end of the array
        case rapidjson::Type::kNumberType:
          // set the current type to be number
          if (currentArrayType == rapidjson::Type::kNullType) {
            currentArrayType = value[i].GetType();
            // keep track of what kind of number it is
            if (value[i].IsInt())
              isInt = true;
          }

          // check if the type is what we expect
          if (currentArrayType == value[i].GetType()) {
            // ensure that they are both ints 
            if (isInt && value[i].IsInt())
              array->push_back(std::make_any<int>(value[i].GetInt()));
            // ensure that they are both doubles
            else if (!isInt && value[i].IsDouble())
              array->push_back(std::make_any<double>(value[i].GetDouble()));
            // do not support heterogeneous arrays
            else
              JSONMemberError(path, name, " error: heterogeneous arrays not supported");
          // do not support heterogeneous arrays
          } else
            JSONMemberError(path, name, " error: heterogeneous arrays not supported");
          break;

        // error for unsuported types
        default:
          JSONMemberError(path, name, " error: unsupported type");
      }
    }
    // return the array
    return array;
  }

  
  /*********************************************************************/
  /*
   Function: createMember
Description: Create a new member of the object and add it
     Inputs: path    - path to the file that we are parsing
             objects - the vector of all objects created
             obj     - the current object to add the member to
             name    - name of the member to add
             member  - the contents of the member
    Outputs: N/A
   */
  /*********************************************************************/
  static void createMember(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& member) {
    // add the value to the object
    addValue(path, objects, obj, name, member);
  }
  
  /*********************************************************************/
  /*
   Function: createDocumentObjects
Description: create a vector with all of the objects within of the file
     Inputs: path     - file that we are looking through
             document - the object holding all of the objects
    Outputs: the vector of all the objects in the file
   */
  /*********************************************************************/
  static std::vector<DeSerializable*>* createDocumentObjects(const char *path, rapidjson::Document& document) {
    // create a vector to store all of the objects thar we are creating in
    std::vector<DeSerializable*>* objects = new std::vector<DeSerializable*>;

    // create a base object for the whole document that all the objects will parent from
    DeSerializable* obj = DSObject::NewObject();
    // add the object to the vector
    objects->push_back(obj);

    // loop through all of the members and objects at the base level
    for (auto& m : document.GetObject())
      createMember(path, objects, obj, m.name.GetString(), m.value);

    // return the vector of objects
    return objects;
  }
  
  /*********************************************************************/
  /*
   Function: DeSerialize
Description: parse a file and return a vector of the contained gameobjects
     Inputs: filepath - path to the file to parse 
    Outputs: pointer to a vector of objects that were parsed
   */
  /*********************************************************************/
  std::vector<DeSerializable*>* DeSerialize(const char* filepath) {
    // convert the file path to a filestream that json can read
    std::ifstream jsonFile(filepath);
    rapidjson::IStreamWrapper jsonStream(jsonFile);

    // create a document and attempt to parst the stream
    rapidjson::Document document;
    rapidjson::ParseResult ok = document.ParseStream(jsonStream);

    // check if there was a parse error, if so then exit early
    JSONError(ok, filepath);
    if (!ok)
      exit(1);

    // print out that we successfully parsed the document
    std::cout << "parsed "<< filepath << std::endl;

    // parse the document into objects and return them in a vector
    return createDocumentObjects(filepath, document);
  }
}
