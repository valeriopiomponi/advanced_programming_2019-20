#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<fstream>

double fMed(const std::vector<double>& v){
  return v[v.size()/2];
}

double fAve(const std::vector<double>& v){
  double Ave{0};
  for(const auto& x : v)
    Ave += x;
  Ave /= v.size();
  return Ave;
}

double fStd(const std::vector<double>& v, double Ave){
  double Std{0};
  for(const auto& x :v)
    Std += ((x-Ave)*(x-Ave));
  Std /= v.size();
  return Std;
}



int main() {

  
  double n, Med, Ave, Std;
  std::vector<double> v;
  std::string line;

  std::ifstream fin("temperatures.txt");

  while(std::getline(fin, line)){
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
     Std = fStd(v, Ave);
     Med = fMed(v);
     

     std::cout<<"Average temperature: " << Ave << " +- " << Std<< ", The Median is: " << Med << std::endl;
}
