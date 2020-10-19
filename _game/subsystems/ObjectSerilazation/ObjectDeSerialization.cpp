#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include <string>
#include <fstream>
#include "rapidjson/error/en.h"
#include "rapidjson/error/error.h"
#include <vector>
#include "ObjectDeSerialization_private.h"

//#include "DeSerializable.h"

namespace Kiwi {
  // Object DeSerializer Functions
  namespace ObjectSerializer {
    //prototypes
    
    /*********************************************************************/
    /*
         Function: DeSerialize
      Description: parse a file and return a vector of the contained gameobjects
           Inputs: filepath - path to the file to parse 
          Outputs: pointer to a vector of objects that were parsed
    */
    /*********************************************************************/
    std::vector<DeSerializable*>* DeSerialize(const char* filepath) {
      if (!filepath) {
        JSONMemberError("-", "-", "string is |NULL|");
        return NULL;
      }

      // convert the file path to a filestream that json can read
      std::ifstream jsonFile(filepath);
      rapidjson::IStreamWrapper jsonStream(jsonFile);
      
      // create a document and attempt to parst the stream
      rapidjson::Document document;
      rapidjson::ParseResult ok = document.ParseStream(jsonStream);

      // needs to be replaced with proper error printing out
      // check if there was a parse error, if so then exit early
      JSONError(ok, filepath);
      if (!ok)
        return NULL;

      // print out that we successfully parsed the document
      std::cout << "parsed "<< filepath << std::endl;
      
      // parse the document into objects and return them in a vector
      return createDocumentObjects(filepath, document);
    }
  }
}
// TODO
// - arrays within arrays that store different types from eachother are not caught
// - unit tests
// - throw exceptions.....
