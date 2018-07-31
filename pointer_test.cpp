//
//  main.cpp
//  pointers_pract
//
//  Created by Kyra Thompson on 7/31/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    char c = 'a';
    int i = 4092;
    double d = 3.14;
    char* cp = &c;
    int* ip = &i;
    double* dp = &d;
    
    cout << "ip = " << ip << " and its value is " << *ip << " \n";
    cout << "Size of ip is " << sizeof(ip) << endl;
    cout << "cp = " << cp << " and its value is " << *cp << " \n";
    cout << "Size of cp is " << sizeof(cp) << endl;
    cout << "dp = " << dp << " and its value is " << *dp << " \n";
    cout << "Size of dp is " << sizeof(dp) << endl;
    
    cout << "Size of c is " << sizeof(c) << "\n";
    cout << "Size of i is " << sizeof(i) << "\n";
    cout << "Size of d is " << sizeof(d) << "\n";
    
    return 0;
}
