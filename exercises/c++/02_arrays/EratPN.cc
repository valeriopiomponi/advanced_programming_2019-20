#include <iostream>
#include <cmath>



int main() {

  int sqN, j, i;
  
  std::cout<<"enter N\n";
  std::size_t N;
  std::cin>> N;

  sqN = sqrt(N);

  bool* Primes{new bool[N]};


  for(std::size_t i{0}; i<N; i++) {
    Primes[i] = 1;
  }
    

  for(std::size_t i{2}; i < sqN; i++) {
    if (Primes[i] == 1) {
      j = i*i;
      while (j < N){
	Primes[j] = 0;
	j += i;
      }
    }
  }

  for(i=2; i<N; i++){
    
    if(Primes[i] == 1) {
      std::cout<<i<<std::endl;
    }
  }
  

  



}
