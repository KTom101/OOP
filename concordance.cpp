//
//  main.cpp
//  concordance
//
//  Created by Kyra Thompson on 7/10/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//
// This program allows user to input words into a vector and will give
// a word count after

#include <iostream>
#include "std_lib_facilities.h"

int main() {
    vector<string> text;
    vector<int> count;
    string input;
    cout << "Input words: \n";
    //allow user to input words into vector
    while (cin >> input){
        text.push_back(input);
    }
    sort(text);

    string prev = "";
    int counter = 0;
    // for loop counting the words
    cout << "Word Count " << endl;
    for (int i = 1; i < text.size(); i++){
        if ( text[i] == text[i-1] ) {
            counter += 1;
            if (i == int(text.size()-1)){
                counter += 1;
                cout << text[i] << ":" << counter << endl;
            }
        }
        else {
            counter += 1;
            cout << text[i-1] << ": " << counter << endl;
            if (i == int(text.size()-1)){
                cout << text[i] << ":" << counter << endl;
            }
            counter = 0;
        }
    }
}
