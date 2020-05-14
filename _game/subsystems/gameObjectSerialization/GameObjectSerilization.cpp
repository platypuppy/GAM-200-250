#include <iostream>
#include <regex>
#include <fstream>
#include "GameObjectSerilization.h"

std::unordered_map<std::string, std::any> regularExpression(const std::string& checkString) {
  std::unordered_map<std::string, std::any> gameObject;
  
  std::regex regexp("[^_]*_([^:]*): ([^;]*);([^]*)");
  std::smatch matches;

  std::string nextRegex = checkString;
  
  while (std::regex_match(nextRegex, matches, regexp)) {
    

    gameObject.emplace(matches[1].str(), std::make_any<std::string>(matches[2].str()));
    
    nextRegex = matches[3].str();
  }
  
  return gameObject;
}

std::unordered_map<std::string, std::any> readGameObject(const std::string& gameObjectString) {
  std::unordered_map<std::string, std::any> gameObject;
  std::string line;
  
  std::regex regexp("[^]*GameObject \\{([^]+)\\}");
  
  std::smatch matches;

  if (std::regex_match(gameObjectString, matches, regexp))
    return regularExpression(matches[1].str());
  
  
  //      gameObject.emplace(strs.first, std::any_cast<std::string>(strs.second));
      
  return gameObject;
}

std::vector<std::unordered_map<std::string, std::any>> readGameObjectFile(const std::string& filename) {
  std::ifstream objectFile(filename);
  std::vector<std::unordered_map<std::string, std::any>> gameObjects;
  std::string line;

  int scope = 0;
  
  line.push_back(objectFile.get());
  while (objectFile.good()) {
    char temp = objectFile.get();
    line.push_back(temp);

    if (temp == '{')
      scope++;
    if (temp == '}') {
      scope--;
      if (scope == 0) {
        gameObjects.push_back(readGameObject(line));
        line.clear();
      }
    }
  }
  return gameObjects;
}
