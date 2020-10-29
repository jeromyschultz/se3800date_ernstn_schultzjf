#ifndef DATE_H
#define DATE_H

class Date
{
private:
  int month;
  int day;
  int year;
public:
  Date(int Day, int Month, int Year);
  int getDaysInMonth(int m, int y);
  int diffBetweenDates(Date date1, Date date2);
  int getMonth();
  int getDay();
  int getYear();
};

#endif
