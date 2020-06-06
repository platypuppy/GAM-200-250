#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <string>
#include <fstream>
#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"

static void printObject(const rapidjson::Value& obj, int indent);

static const char* kTypeNames[] = {
  "Null",
  "False",
  "True",
  "Object",
  "Array",
  "String",
  "Number"
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
  for (int i = 0; i < times * 3; i++)
    out += string;

  return out;
}

static void printArray(const rapidjson::Value& array, int indent) {
  for (rapidjson::SizeType i = 0; i < array.Size(); i++) {
    if (array[i].IsNumber()) {
      if (array[i].IsInt())
        std::cout << array[i].GetInt();
      else if (array[i].IsDouble())
        std::cout << array[i].GetDouble();
      else
        std::cout << "!int || !double";
    } else if (array[i].IsString())
      std::cout << array[i].GetString();
    else if (array[i].IsBool())
      std::cout << array[i].GetBool();
    else if (array[i].IsObject())
      printObject(array[i], indent);
    else if (array[i].IsArray())
      printArray(array[i], indent);
      
    std::cout << ", ";
  }
}

static void printMember(const std::string& name, const rapidjson::Value& mem, int indent = 0) {
  std::cout << std::string(" ") * indent
            << "Type of |"
            << name
            << "| is "
            << kTypeNames[mem.GetType()]
            << ", = ";

  if (mem.IsString())
    std::cout << mem.GetString();
  else if (mem.IsBool())
    std::cout << mem.GetBool();
  else if (mem.IsArray())
    printArray(mem, indent);
  else if (mem.IsObject())
    printObject(mem, indent);
  else if (mem.IsNumber()) {
    if (mem.IsInt())
      std::cout << mem.GetInt();
    else if (mem.IsDouble())
      std::cout << mem.GetDouble();
    else
      std::cout << "!int || !double";    
  }
  
  std::cout << std::endl;
}

static void printObject(const rapidjson::Value& obj, int indent) {
  /*std::string indentWidth;
  for (unsigned char i = 0; i < indent*3; i++)
  indentWidth.push_back(' ');*/
  std::cout << std::endl;
  for (auto it = obj.MemberBegin(); it != obj.MemberEnd(); ++it) {
    //std::cout << indentWidth;
    printMember(it->name.GetString(), it->value, indent + 1);
  }
}

static void printDoc(rapidjson::Document& doc) {
  for (auto& m : doc.GetObject()) {
    printMember(m.name.GetString(), m.value);
  /*for (auto& it : doc.GetObject())
    printObject(*it);*/
  }
}


int main (void) {
  //std::cout << "-------------" << std::endl;
  //std::cout << "yay code work" << std::endl;
  
  std::ifstream jsonFile("_in/test.json");
  rapidjson::IStreamWrapper jsonStream(jsonFile);
  
  rapidjson::Document document;
  JSONError(document.ParseStream(jsonStream));

  printDoc(document);
      //std::cout << "yay an object" << std::endl;
      
  
  //printDoc(document);

  //std::cout << "-------------" << std::endl;
}
