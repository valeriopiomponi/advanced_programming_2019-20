#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>


int main() {

  std::vector<std::string> words;
  int nw{1};
  std::string l1;
  bool check;
  std::ifstream fin("words.txt");

  std::getline(fin, l1);
  words.push_back(l1); 
  while(std::getline(fin, l1)){
    words.push_back(l1);
   
    nw++;
   
  }
  std::cout << words[0] << std::endl;
  for(auto i = 1u; i < nw; i++) {
    check = 0;
    for(auto j = 0u; j < i; j++) {
      if(words[i] == words [j]){
	check = 1;
        break;
      }
    }
     
    if (check == 0)
      std::cout << words[i] << std::endl;
  }
}
