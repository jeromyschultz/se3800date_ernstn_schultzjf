#include <iostream>
#include <algorithm>
#include <string>
#include "date.h"
#include "datecalc.h"
using namespace std;

int main(int argc, char *argv[]){
  string command;
  string feature;
  string date1;
  string date2;
  if(argc > 0 && argv[1] == "--help"){
    //printHelpMessage();
    return 1;
  } else if (argc > 0){
    command = argv[1];
    transform(command.begin(), command.end(), command.begin(), ::tolower);
    if(command == "datecalc"){
      feature = argv[2];
      if(feature == "-d" || feature == "-D"){
          date1 = argv[3];
          date2 = argv[4];
          int daysApart = performFeatureD(date1, date2);
          cout << daysApart << endl;
      }
    }
  }

  // for(int i = 0; i < argc; i++){
  //   cout << argv[i] << endl;
  // }
}
