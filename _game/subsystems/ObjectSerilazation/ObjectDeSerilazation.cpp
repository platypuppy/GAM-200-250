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

namespace ObjectSerializer {
  static void createMember(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& member);
  static std::vector<std::any>* makeArray(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value);

  
  static void JSONError(rapidjson::ParseResult ok, const char * path) {
    if (!ok)
      std::cerr << path
                << ":"
                << ok.Offset()
                << ": "
                << rapidjson::GetParseError_En(ok.Code())
                << std::endl;
  }

  //JSONMemberError(path, "test", "test error");
  static void JSONMemberError(const char *path, const std::string& key, const char *errorString) {
    std::cerr << path
              << ":\""
              << key
              << "\": "
              << errorString
              << std::endl;
  }

    static DeSerializable* createObject(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value) {
      if (name == "object")
        std::cout << "its an object!";
      
      DeSerializable* object = DSObject::NewObject();
      objects->push_back(object);

      obj->AddComponent("child", std::make_any<DeSerializable*>(object));
      object->AddComponent("parent", std::make_any<DeSerializable*>(obj));
      
      for (auto it = value.MemberBegin(); it != value.MemberEnd(); ++it) {
        createMember(path, objects, object, it->name.GetString(), it->value);
      }
      return object;
    }

  
  static void addValue(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value) {
    switch (value.GetType()) {
    case rapidjson::Type::kNullType:
      JSONMemberError(path, name, " warning: |kNullType| will not be read");
      break;
    case rapidjson::Type::kFalseType:
    case rapidjson::Type::kTrueType:
      if (!obj->AddComponent(name, std::make_any<bool>(value.GetBool())))
        JSONMemberError(path, name, " error: unsupported key");
      break;
    case rapidjson::Type::kObjectType:
      createObject(path, objects, obj, name, value);
      break;
    case rapidjson::Type::kArrayType:
      if (!obj->AddComponent(name, std::make_any<std::vector<std::any>*>(makeArray(path, objects, obj, name, value))))
        JSONMemberError(path, name, " error: unsupported key");
      break;
    case rapidjson::Type::kStringType:
      if (!obj->AddComponent(name, std::make_any<std::string>(value.GetString())))
        JSONMemberError(path, name, " error: unsupported key");
      break;
    case rapidjson::Type::kNumberType:
      if (value.IsInt()) {
        if (!obj->AddComponent(name, std::make_any<int>(value.GetInt())))
          JSONMemberError(path, name, " error: unsupported key");
      } else if (value.IsDouble()) {
        if (!obj->AddComponent(name, std::make_any<double>(value.GetDouble())))
          JSONMemberError(path, name, " error: unsupported key");
      } else
        JSONMemberError(path, name, " error: unsupported number type");
      break;
    default:
      JSONMemberError(path, name, " error: unsupported type");
      break;
    }
  }

  static std::vector<std::any>* makeArray(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& value) {

    std::vector<std::any>* array = new std::vector<std::any>;
    rapidjson::Type currentArrayType = rapidjson::Type::kNullType;
    bool isInt = false;
    
    for (rapidjson::SizeType i = 0; i < value.Size(); ++i) {
      switch(value[i].GetType()) {
      case rapidjson::Type::kNullType:
        JSONMemberError(path, name, " error: unsupported type");
        break;
      case rapidjson::Type::kFalseType:
      case rapidjson::Type::kTrueType:
        if (currentArrayType == rapidjson::Type::kNullType)
          currentArrayType = value[i].GetType();
        if (currentArrayType == value[i].GetType())
          array->push_back(std::make_any<bool>(value[i].GetBool()));
        else
          JSONMemberError(path, name, " error: heterogeneous arrays not supported");
        break;
      case rapidjson::Type::kObjectType:
        if (currentArrayType == rapidjson::Type::kNullType)
          currentArrayType = value[i].GetType();
        if (currentArrayType == value[i].GetType())
          array->push_back(std::make_any<DeSerializable*>(createObject(path, objects, obj, name, value[i])));
        else
          JSONMemberError(path, name, " error: heterogeneous arrays not supported");
        break;
      case rapidjson::Type::kArrayType:
        if (currentArrayType == rapidjson::Type::kNullType)
          currentArrayType = value[i].GetType();
        if (currentArrayType == value[i].GetType())
          array->push_back(std::make_any<std::vector<std::any>*>(makeArray(path, objects, obj, name, value[i])));
        else
          JSONMemberError(path, name, " error: heterogeneous arrays not supported");
        break;
      case rapidjson::Type::kStringType:
        if (currentArrayType == rapidjson::Type::kNullType)
          currentArrayType = value[i].GetType();
        if (currentArrayType == value[i].GetType())
          array->push_back(std::make_any<std::string>(value[i].GetString()));
        else
          JSONMemberError(path, name, " error: heterogeneous arrays not supported");
        break;
      case rapidjson::Type::kNumberType:
        if (currentArrayType == rapidjson::Type::kNullType) {
          currentArrayType = value[i].GetType();
          if (value[i].IsInt())
            isInt = true;
        }
        if (currentArrayType == value[i].GetType()) {
          if (isInt && value[i].IsInt())
            array->push_back(std::make_any<int>(value[i].GetInt()));
          else if (!isInt && value[i].IsDouble())
            array->push_back(std::make_any<double>(value[i].GetDouble()));
          else
            JSONMemberError(path, name, " error: heterogeneous arrays not supported");
        } else
          JSONMemberError(path, name, " error: heterogeneous arrays not supported");
        break;
      default:
        JSONMemberError(path, name, " error: unsupported type");
      }
    }
    return array;
  }

  
  static void createMember(const char *path, std::vector<DeSerializable*>* objects, DeSerializable* obj, const std::string& name, const rapidjson::Value& member) {
    addValue(path, objects, obj, name, member);
  }
  
  static std::vector<DeSerializable*>* createDocumentObjects(const char *path, rapidjson::Document& document) {
    std::vector<DeSerializable*>* objects = new std::vector<DeSerializable*>;

    DeSerializable* obj = DSObject::NewObject();
    objects->push_back(obj);
    
    for (auto& m : document.GetObject())
      createMember(path, objects, obj, m.name.GetString(), m.value);
    
    return objects;
  }
  
  std::vector<DeSerializable*>* DeSerialize(const char* filepath) {
    std::ifstream jsonFile(filepath);
    rapidjson::IStreamWrapper jsonStream(jsonFile);

    rapidjson::Document document;
    JSONError(document.ParseStream(jsonStream), filepath);

    std::cout << "parsed "<< filepath << std::endl;

    return createDocumentObjects(filepath, document);
  }
}
