//
//  main.cpp
//  Reading in
//
//  Created by Kyra Thompson on 7/26/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"


int main() {
    cout << "Enter File Name: ";
    string inName;
    cin >> inName;
    cout << endl;
    
    ifstream infile(inName);
    if(!infile) error("Can't open input file ", inName);
    
    string onName;
    cout << "Please enter name of output file: ";
    cin >> onName;
    ofstream ost(onName);
    //ost.open(onName);
    cout << endl;
    
    if(!ost) error("Can't open output file ", onName);
    int num;
    double temp;
    double barReading;
    char sep1,sep2;
    
    
    while(infile >> num >> sep1 >> temp >> sep2 >> barReading){
        ost << num << "\t" << temp << "\t" << barReading << endl;
    }
  
    ost.close();
    infile.close();
    return 0;
    
}
