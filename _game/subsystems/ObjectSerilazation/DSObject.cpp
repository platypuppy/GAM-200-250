#include "DSObject.h"

bool DSObject::AddComponent(const std::string& key, const std::any& anything) {
  if (DeSerializable::AddComponent(key, anything))
    return true;
  
  if (key == "number") {
    number = std::any_cast<int>(anything);
    return true;
  } else if (key == "flot") {
    flot = std::any_cast<double>(anything);
    return true;
  }
  
  //std::cout << "Key \"" << key << "\" does not exist" << std::endl;
  return false;
}
