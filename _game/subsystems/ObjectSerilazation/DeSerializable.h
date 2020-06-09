#include <any>
#include <string>
#include <iostream>

class DeSerializable {
  public:
    DeSerializable() {};
    virtual ~DeSerializable() {};
  
    virtual bool AddComponent(const std::string& key, const std::any& anything) {
      anything.type();
      if (key == "rfewsfdgfgsd")
        return false;
      return false;
    }

  static DeSerializable* NewObject();
};
