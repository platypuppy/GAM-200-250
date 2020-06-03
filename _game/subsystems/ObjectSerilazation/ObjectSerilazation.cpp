#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <string>
#include <fstream>
#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"

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

int main (void) {
  //std::cout << "-------------" << std::endl;
  //std::cout << "yay code work" << std::endl;
  
  std::ifstream jsonFile("_in/test.json");
  rapidjson::IStreamWrapper jsonStream(jsonFile);
  
  rapidjson::Document document;
  JSONError(document.ParseStream(jsonStream));

  for (auto it = document.MemberBegin(); it != document.MemberEnd(); ++it)
    std::cout << kTypeNames[it->value.GetType()] << std::endl;

  //std::cout << "-------------" << std::endl;
}
