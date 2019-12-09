#include<iostream>

using namespace std;


int main() {

  double in;    ;

  string tocon;

  bool ver{0};

  cout << "enter the lenght\n";

  while(!(cin >> in)){
    cout << "enter a double per dindirindina\n";
    std::cin.clear();
    std::cin.ignore();
  }

  while(ver == 0){
    cout << "enter the the units of measure (meter, inch, foot)\n";
    cin >> tocon;
    if (tocon == "meter") 
      ver = 1;

      
    if( tocon == "inch"){
      ver = 1;
      in *= 0.0254;
    }

    if(tocon == "foot"){
      ver =1;
      in *= 0.3048;
    }
  }

  cout << in << " meter" << endl;
  

}
