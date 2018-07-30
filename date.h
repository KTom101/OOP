//
//  date.hpp
//  date
//
//  Created by Kyra Thompson on 7/20/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//

#ifndef date_h
#define date_h

#include <stdio.h>

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
class Date {
public:
    class Invalid{};
    Date();
    Date(int yy, Month mm , int dd);
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
    int month() const {return int(m);}
    int year() const { return y;}
    int day() const { return d;}
    bool isvalid();
private:
    int y, d;
    Month m;
};
ostream& operator<<(ostream& os, const Date& d);
istream& operator << (istream& is, Date& d);
bool operator==(const Date& d, const Date& d2);
bool operator!=(const Date& d, const Date& d2);
bool leapyear(const int& y);


#endif /* date_h */
