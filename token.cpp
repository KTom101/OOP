//
//  main.cpp
//  token
//
//  Created by Kyra Thompson on 7/12/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"

class Token{
public:
    char kind;
    double value;
};
Token get_token();
vector<Token> tokens;
int main() {
    cout << "Enter an expression: " << endl;
    for(Token t = get_token(); t.kind != 'q'; t = get_token()){
        tokens.push_back(t);
    }
    for (Token tok: tokens){
        if(tok.kind == '8'){
            cout << "A number token with val: " << tok.value << endl;
        }
        else if(tok.kind == 'e'){
            cout << "We recieved an invalid token of value: " << char(tok.value);
            cout << endl;
        }
        else {
            cout << "A token of kind: " << tok.kind << endl;
        }
    }
    return 0;
}

Token get_token() {
    char ch;
    cin >> ch;
    switch(ch) {
        case ';':case'q': case'(': case'+': case ')': case'-':
        case'*': case '/': case '%':
            return Token{ch};
        case '0': case '1': case '2' :case '3': case '4': case '5':
        case '6': case'7': case'8': case '9':
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{'8', val};
        default:
            return Token{'e', double(ch)};
    }
    return Token{'q'};
}
