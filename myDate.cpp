//
// Created by Faisal on 9/26/2021.
// 017838065
#include <iostream>
#include <string>
#include "myDate.h"
using namespace std;
//gregorian to julian and vise versa date converter
int greg2julian(int year, int month, int day) {
    int jd = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 + 367 * (month - 2 - (month-14) / 12 * 12) / 12 - 3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
    return jd;
}
void julian2Greg(int JD, int& month, int& day, int& year) {

    int L = JD + 68569;
    int N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    int I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    int J = 80 * L / 2447;
    int K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N - 49) + I + L;
    year = I;
    month = J;
    day = K;
}
/*-----------------------------------------------------------------------*/
//default constructor
myDate::myDate() {
    day = 11;
    month = 5;
    year = 1959;
}
//overloaded constructor
myDate::myDate(int m, int d, int y) {
    day = d;
    month = m;
    year = y;
}
//display function
void myDate::display() {
    string mName = "";
    if (this->month == 1) { mName = "January"; }
    if (this->month == 2) { mName = "February"; }
    if (this->month == 3) { mName = "March"; }
    if (this->month == 4) { mName = "April"; }
    if (this->month == 5) { mName = "May"; }
    if (this->month == 6) { mName = "June"; }
    if (this->month == 7) { mName = "July"; }
    if (this->month == 8) { mName = "August"; }
    if (this->month == 9) { mName = "September"; }
    if (this->month == 10) { mName = "October"; }
    if (this->month == 11) { mName = "November"; }
    if (this->month == 12) { mName = "December"; }
    cout << mName << " " << this->day << ", " << this->year << endl;
}
//
void myDate::increaseDate(int n) {
  int JD = greg2julian(this->year, this->month, this->day);
  JD += 1;
  julian2Greg(JD, this->month,this->day, this->year);
    
}
//
void myDate::decreaseDate(int n) {
    int JD = greg2julian(this->year, this->month, this->day);
    JD -= 1;
    julian2Greg(JD, this->month,this->day, this->year);
}
//
int myDate::daysBetween(myDate b) {
  int JD = greg2julian(this->year, this->month, this->day);
  int bJD = greg2julian(b.year, b.month, b.day);
  return (bJD - JD);
}
//
int myDate::getDay() {
    return this->day;
}
//
int myDate::getMonth() {
    return this->month;
}
//
int myDate::getYear() {
    return this->year;
}
//
int myDate::dayOfYear() {
  myDate c (1, 1, this->year);
  return c.daysBetween(myDate(month, day, year))+1;
}
//
string myDate::dayName() {
    string dName = "";
    int JD = greg2julian(this->year, this->month, this->day);
    int wDay = JD % 7;

    if (wDay == 0) { dName = "Monday"; }
    if (wDay == 1) { dName = "Tuesday"; }
    if (wDay == 2) { dName = "Wednesday"; }
    if (wDay == 3) { dName = "Thursday"; }
    if (wDay == 4) { dName = "Friday"; }
    if (wDay == 5) { dName = "Saturday"; }
    if (wDay == 6) { dName = "Sunday"; }

    return dName;
}
//----------------------------------------------------------------------------//