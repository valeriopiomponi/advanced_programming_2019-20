#include<iostream>
#include<sstream>
#include<utility>

void TransMatrix(double* p, int R, int C) {
  double App[R*C];
  
  for (std::size_t i{0}; i<C; i++) {
    for(std::size_t j{0}; j<R; j++) {
       App[i*R + j] = p[j*C + i];
   
    }
  }
  
  for(std::size_t k{0}; k< (R*C); k++) {
    p[k]=App[k];
  }
  
  
}

int main(int argc, char* argv[]) {

  int N;
  
  

  std::size_t rows;
  {
    std::istringstream is{argv[1]};
    is >> rows;
  }

  std::size_t cols;
  
  {

    std::istringstream is{argv[2]};
    is >> cols;
  }

  
  N = rows*cols;
  double* ad{new double[N]};
  

  for(int i=0; i<rows; i++){
     
    for(int j=0; j < cols; j++){
      ad[i*cols + j] = j;
    
      std::cout << j;
    }
    std::cout<<"\n";
    
  }

   TransMatrix(ad, rows, cols);

  
  
  for(std::size_t l{0}; l<rows; l++) {
    
    for(std::size_t m{0}; m<cols; m++) {
      
      std::cout<< ad[l*cols + m];
      
    }
    std::cout<<"\n";
    
  }
  
  

}
