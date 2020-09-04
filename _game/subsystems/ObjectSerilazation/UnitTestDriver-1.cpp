#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <gtest/gtest.h>

//#include "DeSerializable.cpp"
//#include "DSObject.h"

#include "ObjectDeSerilazation.h"

/*friend ostream& operator << (ostream& os, const DSObject& dso) {
  os << dso.number << dso.flot;
  return os;
}

static const char* BoolConvert[] = {
  "false",
  "true"
};


std::string operator * (const std::string& string, int times) {
  std::string out;
  for (int i = 0; i < times * 2; i++)
    out += string;

  return out;
}*/


TEST(TestingTest, test) {
  ASSERT_EQ(-1, -1);
}

TEST(TestingTest, otherTest) {
  ASSERT_EQ(1, -1);
}


int main (int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
  /*  std::vector<DeSerializable*>* objects = ObjectSerializer::DeSerialize("_in/test.json");
  
  std::cout << "delete?" << std::endl;
  for (long long int i = objects->size()-1; i >= 0; i--) {
    std::cout << "would delete: " << (*objects)[i] << std::endl;
    delete (*objects)[i];
  }
  delete objects;*/
}

