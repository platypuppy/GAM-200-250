#include <any>
#include <string>
#include <iostream>

#ifndef DESERIALIZABLE
#define DESERIALIZABLE
class DeSerializable {
  public:
    DeSerializable() {};
    virtual ~DeSerializable() {};
  
    virtual bool AddComponent(const std::string& key, const std::any& anything) {
      return false;
    }

  static DeSerializable* NewObject();
};
#endif
