
#include <cmath>
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

int Date::getDaysInMonth(int m, int y){

  if((m == 1) || (m == 3) || (m = 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)){
    return 31;
  } else if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
    return 30;
  } else {
    if(y%4 == 0) {
      return 29;
    } else {
      return 28;
    }
  }
}

int Date::diffBetweenDates(Date date1, Date date2){
  int day1 = date1.getDay();
  int month1 = date1.getMonth();
  int year1 = date1.getYear();
  int day2 = date2.getDay();
  int month2 = date2.getMonth();
  int year2 = date2.getYear();
  int yearsApart = abs(year2 - year1);
  int monthsApart = 0;
  int daysApart = 0;
  int month;
  int year;
  if(yearsApart == 0){
    monthsApart = month2 - month1 - 1;
    if(monthsApart >= 0){
      month = month1 + 1;
      for(int i = 0; i < monthsApart; i ++){
        daysApart += getDaysInMonth(month, year1);
        month++;
      }
      daysApart += getDaysInMonth(month1, year1) - day1;
      daysApart += day2;
    } else if (monthsApart == -1){
      daysApart = day2 - day1;
    }
  } else {
    if(month1 < month2){
      monthsApart = month2 - month1 - 1 + (12 * yearsApart);
    } else {
      monthsApart = (11 - month1 + month2) + (12 * (yearsApart-1));
    }
    month = (month1 % 12) + 1;
    year = year1;
    for(int i = 0; i < monthsApart; i++){
      daysApart += getDaysInMonth(month, year);
      month += 1;
      if(month > 12){
        month = 1;
        year += 1;
      }
    }
    daysApart += getDaysInMonth(month1, year1) - day1;
    daysApart += day2;
  }

  return daysApart;

}
