#include <iostream>
#include <vector>

enum class month{jan=1, feb, mar, apr, may, jui, jul, aug, sep, oct, nov, dec};

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
 
  
  int day() const{

    return _d;
  }

  month fmonth() const{

    return _m;
  }

  int year() const{

    return _y;
  }

  void add_days(const unsigned int n) {

    
    
    for(auto i{0}; i<n; i++){

      add_day();
    }
  }

  void add_day(){
    

    switch(_m){
    case month::jan: case month::mar: case month::may: case month::jul: case month::aug: case month::oct: case month::dec:
      if(_d < 31){
	_d += 1;
      }

      else if(_m != month::dec) {
	_d = 1;
	_m = month(int(_m) +1);
      }

      else {
	_d = 1;
	_m = month::jan;
	_y += 1;
      }
    
      break;

    case month::feb: case month::apr: case month::jui: case month::sep: case month::nov:
      if(_d < 30){
       _d += 1;
      }

      else {
	_d = 1;
	_m = month(int(_m)+1);
      }

      break;
    }
  }
    

};


bool operator==(const date& lhs, const date& rhs){if(lhs.day()==rhs.day() && lhs.fmonth()==rhs.fmonth() && lhs.year()==rhs.year()){return true;}
  else {return false;}};

std::ostream& operator<<(std::ostream& os, const date& d){
  os << "dd/mm/year:"<< d.day() << "/"<< int(d.fmonth()) << "/"<< d.year();
  return os;
};

using namespace std;

int main(){

  month mon{month::jan};

  date pd{1, mon, 2000};

  pd.add_days(367);

  date pe{1, mon, 1999};

  pe.add_days(734);

  if(pe==pd){
    cout<<"daje"<<endl;
  }

  cout << pd.day()<< "-" << int(pd.fmonth())<< "-"<< pd.year() << endl;

}
