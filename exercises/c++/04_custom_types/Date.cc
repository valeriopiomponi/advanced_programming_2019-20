#include <iostream>
#include <vector>

enum class month{jan, feb, mar, apr, may, jui, jul, aug, sep, oct, nov, dec};

class date {

  int _d;
  month _m;
  int _y;

  public:
  date(const int d,const month  m ,const int y)
    :
    _d{d},
    _m{m},
    _y{y}
  {}
 
  
  int day(const int _d) {

    return _d;
  }

  month fmonth(const month _m) {

    return _m;
  }

  int year(const int _y) {

    return _y;
  }

  void add_days(const unsigned int n) {

    
    
    for(auto i{0}; i<n; i++){

      add_day();
    }
  }

  void add_day(){
    

    switch(_m){
    case _m==month::jan: case _m==month::mar: case _m==month::may: case _m==month::jul: case _m==month::aug: case _m==month::oct: case _m==month::dec:
      if(d < 31){
	_d += 1;
      }

      else if(_m =! month::dec) {
	_d = 1;
	_m = _m(int(_m) +1));
      }

      else {
	_d = 1;
	_m = month::jan;
	_y =+ 1;
      }
    }
	
	  
    

    
    

};


using namespace std;

int main(){

  month mon{month::jan};

  date pd{5, mon, 2000};

  pd.add_days(5);

  cout<< pd._d << endl;

}
