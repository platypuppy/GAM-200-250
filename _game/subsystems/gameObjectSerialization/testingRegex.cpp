#include <iostream>
#include <regex>
#include <string>

int main (void) {
  std::string str = "\n   \tborder: asfdgs\ndfljhgfs;";

  std::regex regexp("[ \t\n]*([^:]+): ([^]*);");

  //std::string str = "asdffasdfasdf";
  //std::regex regexp("(.*)");
  
  std::smatch matches;
  
  if(std::regex_match(str, matches, regexp)) {
    std::cout << "match" << std::endl;

    for (size_t i = 0; i < matches.size(); ++i)
      std::cout << i << " : " << matches[i].str() << std::endl;
  } else {
    std::cout << "no match";
  }
    
  return 0;
}
