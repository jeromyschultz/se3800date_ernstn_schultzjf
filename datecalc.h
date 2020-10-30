#ifndef DATECALC_H
#define DATECALC_H

#include <string>

int diffBetweenDates(Date date1, Date date2);
int getDaysInMonth(int m, int y);
int performFeatureD(std::string date1, std::string date2);
int determineDayOfWeek(Date date1);
int staggerMonths(int m);
bool isLeapYear(int y);


#endif
