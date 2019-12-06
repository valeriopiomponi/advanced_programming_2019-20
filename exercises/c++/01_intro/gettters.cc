#include<iostream>



void get_int() {

  int x;
 

  std::cout << "enter an int" << std::endl;


  while (!(std::cin >> x)) {
    std::cout << "input is not an integer" << std::endl;
    std::cin.clear();
    std::cin.ignore();
   
  }
  std::cout << x << std::endl;
}

void get_double() {

  double x;

  std::cout << "enter a double" << std::endl;

  while (!(std::cin >> x)) {
    std::cout << "input is not an double" << std::endl;
    std::cin.clear();
    std::cin.ignore();
   
  }
  std::cout << x << std::endl;
}

int main () {

  get_double();
  get_int();
}
