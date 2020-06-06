#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <string>
#include <fstream>
#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"

static void printMember(const std::string& name, const rapidjson::Value& mem, int indent = 0);
static void printArray(const rapidjson::Value& array, int indent);
static void printObject(const rapidjson::Value& obj, int indent);

/*static const char* kTypeNames[] = {
  "Null",
  "False",
  "True",
  "Object",
  "Array",
  "String",
  "Number"
  };*/

static const char* BoolConvert[] = {
  "false",
  "true"
};

static void JSONError(rapidjson::ParseResult ok) {
  if (!ok)
    std::cerr << "JSON parse error: "
              << rapidjson::GetParseError_En(ok.Code())
              << " ("
              << ok.Offset()
              << ")"
              << std::endl;  
}

std::string operator * (const std::string& string, int times) {
  std::string out;
  for (int i = 0; i < times * 2; i++)
    out += string;

  return out;
}

static void printValue(const rapidjson::Value& val, int indent) {
  switch (val.GetType()) {
    case rapidjson::Type::kNullType:
      break;
    case rapidjson::Type::kFalseType:
      std::cout << BoolConvert[val.GetBool()];
      break;
    case rapidjson::Type::kTrueType:
      std::cout << val.GetBool();
      break;
    case rapidjson::Type::kObjectType:
      printObject(val, indent);
      break;
    case rapidjson::Type::kArrayType:
      printArray(val, indent);
      break;
    case rapidjson::Type::kStringType:
      std::cout << "\"" << val.GetString() << "\"";
      break;
    case rapidjson::Type::kNumberType:
      if (val.IsInt())
        std::cout << val.GetInt();
      else if (val.IsDouble())
        std::cout << val.GetDouble();
      else
        std::cout << "!int || !double";    
      break;
    default:
      break;
  }
}

static void printArray(const rapidjson::Value& array, int indent) {
  std::cout << "[ ";
  for (rapidjson::SizeType i = 0; i < array.Size(); i++) {
    printValue(array[i], indent);
    if (i < array.Size()-1)
      std::cout << ", ";
  }
  std::cout << " ]";
}

static void printMember(const std::string& name, const rapidjson::Value& mem, int indent) {
  std::cout << std::string(" ") * indent
            << "\""
            << name
            << "\": ";
  //          << kTypeNames[mem.GetType()]
  //          << ", = ";
  printValue(mem, indent);
  
  std::cout << ",";
  
  std::cout << std::endl;
}

static void printObject(const rapidjson::Value& obj, int indent) {
  std::cout << "{"<< std::endl;
  for (auto it = obj.MemberBegin(); it != obj.MemberEnd(); ++it) {
    printMember(it->name.GetString(), it->value, indent + 1);
  }
  std::cout << std::string(" ") * indent
            << "}";
}

static void printDoc(rapidjson::Document& doc) {
  std::cout << "{" << std::endl;
  for (auto& m : doc.GetObject()) {
    printMember(m.name.GetString(), m.value, 1);
  }
  std::cout << std::endl << "}" << std::endl;
}


int main (void) {
  std::ifstream jsonFile("_in/test.json");
  rapidjson::IStreamWrapper jsonStream(jsonFile);
  
  rapidjson::Document document;
  JSONError(document.ParseStream(jsonStream));

  printDoc(document);
}



//================================================================
/*
TODO:
- figure out type to object
- make objects to can be created
- make arrays into vectors
- make things added to objects
*/
