#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <gtest/gtest.h>
#include "rapidjson/document.h"

//#include "DeSerializable.cpp"
//#include "DSObject.h"

#include "ObjectDeSerialization_private.h"
//#include "ObjectDeSerialization.h"


int* returnNULL () {
  return NULL;
}



namespace Test {
  //============================================================================
  // DeSerializable
  //============================================================================
  // check if valid json file is used that a valid pointer is returned
  TEST(DeSerialize, basic_JSON_file) {
    testing::internal::CaptureStdout();
    
    // this should return a valid pointer
    EXPECT_NE(static_cast<void*>(NULL), Kiwi::ObjectSerializer::DeSerialize("UnitTestData/Basic.json"));
    std::string clear_out = testing::internal::GetCapturedStdout();
  }

  // test that the length of the vector is 1 for a blank json file
  TEST(DeSerialize, blank_JSON_file_correct_vector_length) {
    testing::internal::CaptureStdout();
    EXPECT_EQ(1, (Kiwi::ObjectSerializer::DeSerialize("UnitTestData/Basic.json"))->size());
    std::string clear_out = testing::internal::GetCapturedStdout();
  }

  // check that invalid file paths are handled correctly
  TEST(DeSerialize, invalid_file_path) {
    testing::internal::CaptureStderr();
    EXPECT_EQ(static_cast<void*>(NULL), Kiwi::ObjectSerializer::DeSerialize("UnitTestData/invalid_filepath.json"));
    std::string clear_out = testing::internal::GetCapturedStderr();
  }

  // check that the parsed message is correct
  TEST(DeSerialize, parse_message_based_on_input) {
    testing::internal::CaptureStdout();
    Kiwi::ObjectSerializer::DeSerialize("UnitTestData/Basic.json");
    EXPECT_EQ("parsed UnitTestData/Basic.json\n", testing::internal::GetCapturedStdout());
    testing::internal::CaptureStdout();
    Kiwi::ObjectSerializer::DeSerialize("UnitTestData/blank.json");
    EXPECT_EQ("parsed UnitTestData/blank.json\n", testing::internal::GetCapturedStdout());
  }

  // check the stderr for an invalid file name
  TEST(DeSerialize, parse_message_invalidfilename) {
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    Kiwi::ObjectSerializer::DeSerialize("UnitTestData/invalid_filepath.json");
    EXPECT_EQ("", testing::internal::GetCapturedStdout());
    EXPECT_EQ("UnitTestData/invalid_filepath.json:0: The document is empty.\n", testing::internal::GetCapturedStderr());
  }

  // check if invalid strings are handled
  TEST(DeSerialize, invalid_string) {
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    EXPECT_EQ(NULL, Kiwi::ObjectSerializer::DeSerialize(static_cast<char*>(NULL)));
    std::string clear_out = testing::internal::GetCapturedStdout();
    clear_out = testing::internal::GetCapturedStderr();
  }

  // check if hte output of invalid strings are correct
  TEST(DeSerialize, invalid_string_message) {
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    Kiwi::ObjectSerializer::DeSerialize(static_cast<char*>(NULL));
    EXPECT_EQ("", testing::internal::GetCapturedStdout());
    EXPECT_EQ("-:\"-\": string is |NULL|\n", testing::internal::GetCapturedStderr());
  }

  // ensure that there are no spaces in filenames
  TEST(DeSerialize, invalid_filepath_spaces) {
    testing::internal::CaptureStdout();
    testing::internal::CaptureStderr();
    EXPECT_EQ(static_cast<void*>(NULL), Kiwi::ObjectSerializer::DeSerialize("UnitTestData/file with spaces.json"));
    EXPECT_EQ("", testing::internal::GetCapturedStdout());
    EXPECT_EQ("UnitTestData/file with spaces.json:\"-\": has spaces in file name, not supported\n", testing::internal::GetCapturedStderr());
  }
  
  /*TEST(ParsingJSON, createObject) {
    rapidjson::Value val;
    val.SetInt(10);
    std::string str("no");
    //Kiwi::ObjectSerializer::createObject(NULL, NULL, NULL, str, val);
    //EXPECT_EQ(NULL, Kiwi::ObjectSerializer::createObject(NULL, NULL, NULL, std::string("no"), val));
    //EXPECT_EQ(NULL, returnNULL());
    //EXPECT_EQ(12, 12);
    }*/
}
  
int main (int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  int allTests = RUN_ALL_TESTS();
  //std::cout << testing::internal::GetCapturedStdout();
  return allTests;
  //return RUN_ALL_TESTS();
  
  /*  std::vector<DeSerializable*>* objects = ObjectSerializer::DeSerialize("_in/test.json");
      
      std::cout << "delete?" << std::endl;
      for (long long int i = objects->size()-1; i >= 0; i--) {
      std::cout << "would delete: " << (*objects)[i] << std::endl;
      delete (*objects)[i];
      }
      delete objects;*/
}
