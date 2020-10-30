
#include "date.h"
#include "datecalc.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int performFeatureD(string date1, string date2){
  string y1 = date1.substr(0, 4);
  string m1 = date1.substr(5, 2);
  string d1 = date1.substr(8, 2);
  string y2 = date2.substr(0, 4);
  string m2 = date2.substr(5, 2);
  string d2 = date2.substr(8, 2);
  int year1 = stoi(y1);
  int month1 = stoi(m1);
  int day1 = stoi(d1);
  int year2 = stoi(y2);
  int month2 = stoi(m2);
  int day2 = stoi(d2);
  Date startingDate(day1, month1, year1);
  Date endDate(day2, month2, year2);
  return diffBetweenDates(startingDate, endDate);

  // cout << "Year 1: "<< year1 << endl << "Month 1: " << month1 << endl << "Day 1:" << day1;
}

int diffBetweenDates(Date date1, Date date2){
  int day1 = date1.getDay();
  int month1 = date1.getMonth();
  int year1 = date1.getYear();
  int day2 = date2.getDay();
  int month2 = date2.getMonth();
  int year2 = date2.getYear();
  int yearsApart = abs(year2 - year1);


  int totalDays1 = day1;
  int year = year1;
  int totalDays2 = day2;
  for(int i = 1; i < month1; i++){
    totalDays1 += getDaysInMonth(i, year);
  }
  if(yearsApart > 0){
    for(int i = 0; i < yearsApart; i++){
      for(int j = 1; j <= 12; j++){
        totalDays2 += getDaysInMonth(j, year);
      }
      year += 1;
    }
  }
  for(int i = 1; i < month2; i++){
    totalDays2 += getDaysInMonth(i, year);
  }


  return totalDays2 - totalDays1;
}

int getDaysInMonth(int m, int y){

  if((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)){
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

/**
* Calculates which day of the week the given date is on
* 0 is Sunday, 6 is Saturday
*
**/
int determineDayOfWeek(Date date1){
  int d = date1.getDay();
  int m = staggerMonths(date1.getMonth());
  int y = date1.getYear();

  //splitting year in half
  int firstHalf, secondHalf=0, len;
  len = floor(log10(abs(y))) + 1;
  firstHalf = y / pow(10, len / 2);
  secondHalf = y - firstHalf * pow(10, len / 2);

  int answer = d + (int)(((13*m)-1)/5) + secondHalf +
  (int)(secondHalf/4) + (int)(firstHalf/4) - 2*firstHalf;

  if(answer < 0){
    int x = 0;
    int i = 1;
    while (x>answer){
      x = -7 * i;
      i++;
    }
    answer = abs(x-answer);

  }else{
    answer = answer % 7;
  }

  return answer;


}

bool isLeapYear(int y){
  if (y % 4 != 0){
    return false;
  } else if (y % 25 != 0){
    return true;
  } else if (y % 16 != 0){
    return false;
  } else {
    return true;
  }
}

int staggerMonths(int m){
  int x = 0;
  if(m == 1){
    x = 11;
  }else if(m == 2){
    x = 12;
  }else if(m == 3){
    x = 1;
  }else if(m == 4){
    x = 2;
  }else if(m == 5){
    x = 3;
  }else if(m == 6){
    x = 4;
  }else if(m == 7){
    x = 5;
  }else if(m == 8){
    x = 6;
  }else if(m == 9){
    x = 7;
  }else if(m == 10){
    x = 8;
  }else if(m == 11){
    x = 9;
  }else if(m == 12){
    x = 10;
  }
  return x;

}
