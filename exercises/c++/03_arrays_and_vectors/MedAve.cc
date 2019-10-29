#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>


double fAve(const std::vector<double>& v){
  double Ave{0};
  for(const auto& x : v)
    Ave += x;
  Ave /= v.size();
  return Ave;
}

double fMed(const std::vector<double>& v, double Ave){
  double Med{0};
  for(const auto& x :v)
    Med += ((x-Ave)*(x-Ave));
  Med /= v.size();
  return Med;
}



int main() {

  
  double n, Med, Ave;
  std::vector<double> v;
  std::string line;

  while(std::getline(std::cin, line)){
    {
    std::istringstream is{line};
    is >> n;
    }
    
    v.push_back(n);
  }


   std::sort( v.begin(), v.end() );

   for (auto i = 0u; i < v.size(); i++) {
     std::cout << v[i] << std::endl;
     }

     Ave = fAve(v);
     Med = fMed(v, Ave);

     std::cout<<"Average temperature: " << Ave << "+ o - " << Med<<std::endl;
}
