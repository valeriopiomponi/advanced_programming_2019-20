#include <iostream>

int main() {

  int i{1};

  std::string line;
  std::string l1;
  std::string l2;

  std::getline(std::cin, l1);
  while(std::getline(std::cin, line)){
 

    if (line == l1) {
      i += 1;
      
    }

    else {

      std::cout << i << l1 << std::endl;
      i = 1;
      l1 = line;
    }

    
  }
    std::cout << i << line << std::endl;
  
  return 0;
}
