#include<iostream>


template <typename T>
T* InitArr(int n) {
  T* da{new T[n]};

  for(std::size_t i{0}; i < n; ++i) { 
    std::cout << i << ": enter a number\n";
    std::cin >> da[i];
  }

  return  da;
}

template <typename T>
void PrintRev (int n, T* da) {
  int i{n}, j{0};
  
  while(i>0) {
    --i;
    std::cout<< j <<": " << da[i] << std::endl;
    j++;
  }


}


int main() {
  int n;
  int* da;
  
  std::cout << "enter the lenght of the array\n";
  std::cin >>  n;

  da = InitArr<int>(n);

  PrintRev(n, da);

}