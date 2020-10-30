// Jeromy Schultz and Noah Ernst
// se3800date_ernstn_schultzjf
// 2020-10-30

#include "date.h"
#include "datecalc.h"
#include <cmath>
#include <string>
#include <regex>
#include <iostream>
using namespace std;


/*
Prints a message of available commands
*/
void printHelpMessage(){
  cout << "The list of available commands are the following:" << endl;
  cout << "-d: use this command followed by two dates in the format YYYY-MM-DD to see the number of days between dates" << endl;
  cout << "-w: use this command followed by a date in the format YYYY-MM-DD to see the day of the week of the specified date" << endl;
}

/*
Validates a string in the format YYYY-MM-DD
*/
bool validateDate(string date){
  regex exp("(^\\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\\d|3[01])$)");
  bool isDateMatched = regex_match(date, exp);
  if(!isDateMatched){
    cout << "Incorrect date format for : " << date << endl;
    cout << "Correct format: YYYY-MM-DD where YYYY is [0, 9999], MM is [1,12] and DD [1,31]" << endl;
    return 0;
  } else {
    string y = date.substr(0, 4);
    string m = date.substr(5, 2);
    string d = date.substr(8, 2);
    int year = stoi(y);
    int month = stoi(m);
    int day = stoi(d);
    if(day > getDaysInMonth(month, year)){
      cout << "Error: Date " << date << " does not exist on calendar" << endl;
      return 0;
    }
  }
  return isDateMatched;
}

/*
Takes in a validated string in the format YYYY-MM-DD and calls the
function that returns the day of the week of the date
*/
int performFeatureW(string date1){
  string y1 = date1.substr(0, 4);
  string m1 = date1.substr(5, 2);
  string d1 = date1.substr(8, 2);
  int year1 = stoi(y1);
  int month1 = stoi(m1);
  int day1 = stoi(d1);
  Date date(day1, month1, year1);
  return determineDayOfWeek(date);
}

/*
Take int two validated strings in the format YYYY-MM-DD and calls the
function that returns the number of days between the two dates
*/
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

}

/*
Returns the number of days between dates
*/
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


  return abs(totalDays2 - totalDays1);
}

/*
Returns the number of days in the given month and year
*/
int getDaysInMonth(int m, int y){

  if((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)){
    return 31;
  } else if ((m == 4) || (m == 6) || (m == 9) || (m == 11)) {
    return 30;
  } else {
    if(y%4 == 0) {
      if(y%100 == 0 && y%400 != 0){
        return 28;
      } else {
        return 29;
      }
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

  if(m > 10){
    secondHalf--;
  }

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
