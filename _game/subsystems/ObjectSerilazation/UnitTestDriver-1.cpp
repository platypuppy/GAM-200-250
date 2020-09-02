#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <string>
#include <fstream>
#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"
#include <vector>

//#include "DeSerializable.cpp"
//#include "DSObject.h"

#include "ObjectDeSerilazation.h"

static const char* BoolConvert[] = {
  "false",
  "true"
};

std::string operator * (const std::string& string, int times) {
  std::string out;
  for (int i = 0; i < times * 2; i++)
    out += string;

  return out;
}

int main (void) {
  std::vector<DeSerializable*>* objects = ObjectSerializer::DeSerialize("_in/test.json");
  
    
  std::cout << "delete?" << std::endl;
  for (long long int i = objects->size()-1; i >= 0; i--) {
    std::cout << "would delete: " << (*objects)[i] << std::endl;
    delete (*objects)[i];
  }
  delete objects;
}

