#include "GameObjectSerilization.h"
#include <iostream>
#include <iomanip>

std::ostream& operator << (std::ostream& os, std::any& anything) {
  const auto& type = anything.type();

  if (type == typeid(int))
    os << std::any_cast<int>(anything);
  else if (type == typeid(float))
    os << std::any_cast<float>(anything);
  else if (type == typeid(std::string))
    os << std::any_cast<std::string>(anything);

  return os;
}

std::ostream& operator << (std::ostream& os, std::unordered_map<std::string, std::any> un_map) {
  for (auto& it : un_map)
    os << std::setw(15)
       << it.first
       << " : "
       << it.second
       << std::endl;

  return os;
}

int main(void) {
  std::vector<std::unordered_map<std::string, std::any>> gameObjects = readGameObjectFile("_in/GO1.txt");

  for (auto& it : gameObjects)
    std::cout << it << std::endl;
  
  return 0;
}
