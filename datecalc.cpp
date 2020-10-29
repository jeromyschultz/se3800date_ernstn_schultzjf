
#include "date.h"
#include "datecalc.h"
#include <cmath>

int diffBetweenDates(Date date1, Date date2){
  int day1 = date1.getDay();
  int month1 = date1.getMonth();
  int year1 = date1.getYear();
  int day2 = date2.getDay();
  int month2 = date2.getMonth();
  int year2 = date2.getYear();
  int yearsApart = abs(year2 - year1);
  int monthsApart = 0;
  int daysApart = 0;
  // int month;
  // int year;
  // if(yearsApart == 0){
  //   monthsApart = month2 - month1 - 1;
  //   if(monthsApart >= 0){
  //     month = month1 + 1;
  //     for(int i = 0; i < monthsApart; i ++){
  //       daysApart += getDaysInMonth(month, year1);
  //       month++;
  //     }
  //     daysApart += getDaysInMonth(month1, year1) - day1;
  //     daysApart += day2;
  //   } else if (monthsApart == -1){
  //     daysApart = day2 - day1;
  //   }
  // } else {
  //   if(month1 < month2){
  //     monthsApart = month2 - month1 - 1 + (12 * yearsApart);
  //   } else {
  //     monthsApart = (11 - month1 + month2) + (12 * (yearsApart-1));
  //   }
  //   month = (month1 % 12) + 1;
  //   year = year1;
  //   for(int i = 0; i < monthsApart; i++){
  //     daysApart += getDaysInMonth(month, year);
  //     month += 1;
  //     if(month > 12){
  //       month = 1;
  //       year += 1;
  //     }
  //   }
  //   daysApart += getDaysInMonth(month1, year1) - day1;
  //   daysApart += day2;
  //   //get rid of the start dy and end day to get the days in between
  //   daysApart -= 2;
  // }

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
