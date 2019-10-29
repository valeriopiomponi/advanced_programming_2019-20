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

  int fmonth(const int _m) {

    return _m;
  }

  int year(const int _y) {

    return _y;
  }

  void add_days(const unsigned int n) {

    int d, y;
    month m;

    d = _d;
    m = _m;
    y = _y;
    
    for(auto i{0}; i<n; i++){

      add_day(d);
    }
  }

  void add_day(){
    int d, y;
    month m;

    d=_d;
    m = _m;
    y = _y;
    

};


using namespace std;

int main(){

  month mon{month::jan};

  date pd{5, mon, 2000};

  pd.add_days(5);

  cout<< pd._d<< endl;

}
