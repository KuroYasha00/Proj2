//
// Created by Faisal on 9/26/2021.
// 017838065

#ifndef MYDATE_H
#define MYDATE_H
#include <string>
using namespace std;

class myDate{
private:
    int day, month, year;
public:
    //default constructor
    myDate();
    //overloaded constructer
    myDate(int m, int d, int y);
    //displays date in format(May 11, 2000)
    void display();
    //increments the date by a number of days n
    void increaseDate(int n);
    //decrements the date by a number of days n
    void decreaseDate(int n);
    //returns the number of days between the date and a date d will be positive or negative depending on date d
    int daysBetween(myDate d);
    //return functions in integer format
    int getDay();
    int getMonth();
    int getYear();
    //return a number of days since the year began
    int dayOfYear();
    //returns the name of the current day of the week
    string dayName();


};
#endif //MYDATE_H
