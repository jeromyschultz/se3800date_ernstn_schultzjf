#include <iostream>
#include <string>
#include "date.h"
#include "datecalc.h"
using namespace std;

int main(int argc, char *argv[]){
  string command;
  string feature;
  int day1;
  int month1;
  int year1;
  int day2;
  int month2;
  int year2;
  cout << "Enter month 1: ";
  cin >> month1;
  cout << "Enter day 1: ";
  cin >> day1;

  cout << "Enter year 1: ";
  cin >> year1;

  cout << "Enter month 2: ";
  cin >> month2;
  cout << "Enter day 2: ";
  cin >> day2;
  cout <<  "Enter year 2: ";
  cin >> year2;

  cout << endl;

  Date Date1(day1, month1, year1);
  Date Date2(day2, month2, year2);
  int daysApart;
  daysApart = diffBetweenDates(Date1, Date2);
  cout << "Days Apart: " << daysApart;



  // for(int i = 0; i < argc; i++){
  //   cout << argv[i] << endl;
  // }
}
