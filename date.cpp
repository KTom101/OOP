//
//  date.cpp
//  date
//
//  Created by Kyra Thompson on 7/20/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//
#include "std_lib_facilities.h"
#include "date.h"
int daysInMonth(const int m, const int y){
    vector<int> days = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};
    vector<int> leapday = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(leapyear(y)){
        return leapday[m];
    }
    else{
        return days[m];
    }
            
}
vector<string> months = {"","January", "Febuary", "March", "April", "May", "June",
    "July", "August","September", "October", "November", "December"};

//vector<Month> enumMonths = {0,1,2,3,4,5,6,7,8,9,10,11,12};

Date::Date() : y{2000}, m{Month::jan}, d{1} {}
Date::Date(int yy, Month mm, int dd) : y{yy}, m{mm}, d{dd}{
    if(!isvalid()){
        try{
            throw Invalid();
        }
        catch(...){
            cout << "Invalid input for date try again \n";
        }
    }
}
void Date::add_day(int n){
    while(n > daysInMonth(int(m), y)){
        int remainder = daysInMonth(int(m), y) - d;
        n -= remainder;
        d = 0;
        add_month(1);
    }
    d += n;
}
            
void Date::add_month(int n){
    for(int i = 0; i<n; i++){
        int mon = month();
        mon = (mon+1)%12;
        m = Month(mon);
        if(m == Month::jan){
            y += 1;
        }
    }
}
void Date::add_year(int n){
    for(int i = 0; i<n; i++){
        y+=1;
    }
}


                
bool Date::isvalid() {
    if(int(m)< 1 || int(m) > 12) return false;
    else if(d < 1 || d > 31) return false;
    else if( d >= 1 || d <= 31){
        switch (int(m)) {
            case 2:
                if (d > 28 && leapyear(y) == 0) {
                    return false;
                }
                else if (d > 29){
                    return false;
                }
                else {
                    return true;
                }
                break;
                
            case 4: case 6: case 9: case 11:
                if(d > 30){
                    return false;
                }
                break;
                
            default:
                return true;
        }
    }
    else if (y < 1) return false;
    return true;

}

bool leapyear(const int &y){
    if((((y % 4) == 0) && ((y % 100) != 0 )) || (y%400) == 0) return true;
    return false;
}
    
ostream& operator << (ostream& os, const Date& d){
    return os << months[int(d.month())] << " " << d.day() << ',' << d.year();
}

istream& operator << (istream& is, Date& d){
    char par1,comma1,comma2,par2;
    int year,month,day;
    is >> par1 >> year >> comma1 >> month >> comma2 >> day >> par2;
    d = Date(year, Month(month), day);
    return is;

}
bool operator==(const Date& d, const Date& d2){
    if (d.year() == d2.year() && d.month() == d2.month() && d.day() == d2.day()){
        return true;
    }
    return false;
}

bool operator!=(const Date& d, const Date& d2){
    return !(d == d2);
}

