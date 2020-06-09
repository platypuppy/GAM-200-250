#include "DeSerializable.h"

class DSObject : DeSerializable {
  public:
    DSObject() : DeSerializable(), number(12), flot(14.8f) {};

    ~DSObject() {};
  
    virtual bool AddComponent(const std::string& key, std::any& anything) {
      if (DeSerializable::AddComponent(key, anything))
        return true;

      if (key == "number") {
        number = std::any_cast<int>(anything);
        return true;
      } else if (key == "flot") {
        flot = std::any_cast<float>(anything);
        return true;
      }

      std::cout << "Key \"" << key << "\" does not exist" << std::endl;
      return false;
    }

    static DeSerializable* NewObject() {
      return new DSObject();
    }

  private:
    int number;
    float flot;
};
