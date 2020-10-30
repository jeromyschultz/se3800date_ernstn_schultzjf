// Jeromy Schultz and Noah Ernst
// se3800date_ernstn_schultzjf
// 2020-10-30

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
  int getMonth();
  int getDay();
  int getYear();
};

#endif
