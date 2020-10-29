

#include "date.h"
using namespace std;



Date::Date(int Day, int Month, int Year){
  day = Day;
  month = Month;
  year = Year;
}

int Date::getMonth(){
  return month;
}

int Date::getDay(){
  return day;
}

int Date::getYear(){
  return year;
}
