#include <iostream>

int main() {
  int n{100};
  int j{3}, i{0};
  int* primes{new int[n]};
  unsigned int r;

  for(i=0; i<100; i++) {
    primes[i]=0;
  }
  primes[0] = 2;

  i = 0;
  
  while (primes[i] < j){
  
      if(primes[i] == 0) {
	primes[i] = j;
	std::cout<<j<<std::endl;
      }

      
      r = j%primes[i];
      if (r==0){
	j+=1;
	i = 0;
      }

      else {
	i += 1;
      
	if (j>100)
	  break;
    
    }
    
   
    
  }
} 
