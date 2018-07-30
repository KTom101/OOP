//
//  main.cpp
//  date
//
//  Created by Kyra Thompson on 7/20/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"
#include "date.h"



int main() {
    bool done = false;
    char par1,comma1,comma2,par2;
    int year,month,day;
   
    while(!done){
        cout << "What is your date (YYYY,MM,DD): ";
        
        cin >> par1 >> year >> comma1 >> month >> comma2 >> day >> par2;

        Date entered(year,Month(month),day);
        if(entered.isvalid() == 0){
            cout << "Please enter a valid date: "  << endl;
        }
        else{
            cout << "You entered << "  << entered << " >>" << endl;
            done = true;
            
        }
    }
    
    cout << "-----------------------------" << endl;
    Date test(2018, Month::jul ,20);
    cout <<"Printing out a test date: " << endl;
    cout <<  test << endl;
    cout << "Adding 700 days to test date "  << test << ": ";
    test.add_day(700);
    cout << test << endl;
    cout << "Adding 8 months to test date " << test << ": ";
    test.add_month(8);
    cout << test << endl;
    cout << "Adding 3 years to test date " << test << ": ";
    test.add_year(3);
    cout << test << endl;
    cout << "-----------------------------" << endl;
    cout << "Testing equality function: " << endl;
    Date again(2018, Month::jul, 20);
    cout << test << " == " << again << ": " << boolalpha << (test == again) << endl;
    cout << "Testing inequality function: " << endl;
    cout << test << " != " << again << ": " << boolalpha << (test != again) << endl;
//    Date invalid(2018, Month::jul, 32);
    cout << "-----------------------------" << endl;
    cout << "Testing Leap Year: " << endl;
    cout << "leapyear(" << test.year() << ")" <<leapyear(test.year()) << endl;
    cout << "leapyear(1865): " << leapyear(1865) << endl;
    cout << "leapyear(1865): " << leapyear(2016) << endl;

    return 0;
}
