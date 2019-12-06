#include <iostream>

int main() {

  int i{1};

 
  std::string l1;
  std::string l2;

  std::getline(std::cin, l1);
  for(std::string line; std::getline(std::cin, line);){
 

    if (line == l1) {
      i += 1;
      l2=line;
    }

    else if (line != l1) {

      std::cout << i << l1 << std::endl;
      i = 1;
      l1 = line;
    }
    
    
  }
    std::cout << i << l2 << std::endl;
  
  return 0;
}
