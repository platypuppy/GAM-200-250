#include <iostream>
#include <unordered_map>
#include <string>
#include <any>

std::ostream& operator << (std::ostream& os, std::any& anything) {
  const auto& type = anything.type();
  if (type == typeid(int))
    os << std::any_cast<int>(anything);
  else if (type == typeid(float))
    os << std::any_cast<float>(anything);
  
  return os;
}

std::ostream& operator << (std::ostream& os, std::unordered_map<std::string, std::any> un_map) {
  //for (auto it = map.begin(); it != map.end(); ++it)
  for (auto& it : un_map)
    os << it.first << " : " << it.second << std::endl;
  return os;
}

int main (void) {
  std::unordered_map<std::string, std::any> map;

  map.emplace("Hello", std::make_any<int>(14));
  map.emplace("no", std::make_any<int>(452));
  map.emplace("yay an float", std::make_any<float>(4.54));
  
  std::cout << map;

  return 0;
}
