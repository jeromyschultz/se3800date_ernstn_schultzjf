#include <iostream>
#include <algorithm>
#include <string>
#include "date.h"
#include "datecalc.h"
using namespace std;

int main(int argc, char *argv[]){
  string daysOfWeek[6] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  string command;
  string feature;
  string date1;
  string date2;
  if(argc == 2 && argv[1] == "--help"){
    // printHelpMessage();
    return 1;
} else if (argc == 4 || argc == 5){
    command = argv[1];
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if(command == "datecalc"){
      feature = argv[2];
      if(feature == "-d" || feature == "-D"){
          date1 = argv[3];
          date2 = argv[4];
          if(validateDate(date1) && validateDate(date2)){
            int daysApart = performFeatureD(date1, date2);
            cout << daysApart << endl;
            return 1;
          }
      } else if(feature == "-w" || feature == "-W"){
        date1 = argv[3];
        if(validateDate(date1)){
          int dayOfWeek = performFeatureW(date1);
          cout << daysOfWeek[dayOfWeek] << endl;
          return 1;
        }
      }
    } else {
      cout << "Dont recognize command " << command << endl;
      return 0;
    }
  }


}
