#include <string>
#include <vector>

//#include "DeSerializable.h"
#include "ObjectDeSerialization.h"

namespace Kiwi {
  namespace ObjectSerializer {
    //std::vector<DeSerializable*>* DeSerialize(const char* filepath);
    void JSONError(rapidjson::ParseResult ok,
                   const std::string& path);
    
    void JSONMemberError(const std::string& path,
                         const std::string& key,
                         const char * errorString);
    
    DeSerializable* createObject(const std::string& path,
                                 std::vector<DeSerializable*>* objects,
                                 DeSerializable* obj,
                                 const std::string& name,
                                 const rapidjson::Value& value);
    
    void addValue(const std::string& path,
                  std::vector<DeSerializable*>* objects,
                  DeSerializable* obj,
                  const std::string& name,
                  const rapidjson::Value& value);
    
    std::vector<std::any>* makeArray(const std::string& path,
                                     std::vector<DeSerializable*>* objects,
                                     DeSerializable* obj,
                                     const std::string& name,
                                     const rapidjson::Value& value);
    
    void createMember(const std::string& path,
                      std::vector<DeSerializable*>* object,
                      DeSerializable* obj,
                      const std::string& name,
                      const rapidjson::Value& member);
    
    std::vector<DeSerializable*>* createDocumentObjects(const std::string& path,
                                                        rapidjson::Document& document);
    
  }
}
