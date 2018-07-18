//
//  main.cpp
//  calc3
//
//  Created by Kyra Thompson on 7/13/18.
//  Copyright © 2018 Kyra Thompson. All rights reserved.
//

#include <iostream>
#include "std_lib_facilities.h"
const string prompt = "> ";
const string result = "= ";
const char number = '8';
const char quit = 'q';
const char print = ';';

class Token{
public:
    char kind;
    double value;
};
class Token_stream {
public:
    Token get();
    void putback(Token t);
    void ignore(char c);
private:
    Token buffer;
    bool full{false};
};
void Token_stream::putback(Token t){
    buffer = t;
    full = true;
}
Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch(ch) {
        case print:
        case quit:
        case'(':
        case'+':
        case ')':
        case'-':
        case'*':
        case '/':
        case '%':
            return Token{ch};
        case'0': case'1': case'2' :case'3': case'4':
        case'5': case '6': case'7': case'8': case '9': case '.':
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{'8', val};
        default:
            return Token{'e', double(ch)};
    }
    return Token{'q'};
}
void Token_stream::ignore(char c){
    if(full && c == buffer.kind){
        full = false;
        return;
    }
    full = false;
    char ch = 0;
    while(cin >> ch){
        if(ch == c) return;
    }
}
Token_stream ts;
double expression();
double term();
double primary();

double expression() {
    double left = term();
    Token t =ts.get();
    while(true) {
        switch(t.kind){
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                 t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}
double term() {
    double left = primary();
    Token t =ts.get();
    while(true) {
        switch(t.kind){
            case '*':{
                left *= primary();
                t = ts.get();
                break;
            }
            case '/':{
                double div = primary();
                if (div == 0) {
                    error("can't divide by 0");
                }
                left /= div;
                t = ts.get();
                break;
            }
            case '%':{
                double d = primary();
                if(d == 0) error(" divide by zero ");
                left = fmod(left,d);
                t = ts.get();
                break;
            }

            default:
                ts.putback(t);
                return left;

        }

    }
}
double primary() {
    Token t = ts.get();
    switch(t.kind){
        case '-':
            return -primary();
        case '(':{
            double d = expression();
            t = ts.get();
            return d;
        }
        case number:
            return t.value;
        case '+':
            return primary();
        default:
            error("Error: primary expected");

    }
    return t.value;
}
vector<Token> tokens;
//Token_stream ts;
void print_token(Token t){
    cout << "Got token of kind " << t.kind << " with value of " << t.value << endl;
}
void clean_up_mess(){
    ts.ignore(print);

}
void calculate(){
    while (cin){
        try{
            cout << prompt;
            Token t = ts.get();
            while(t.kind == print ) t = ts.get();
            if(t.kind == quit) return;
            ts.putback(t);
            cout << result << expression() << '\n';
        }
        catch(exception& e ){
            cerr<< e.what()<< endl;
            clean_up_mess();

        }
    }
}

int main() {
    try{
        calculate();
        return 0;
    }
    catch(...){
        cerr << "Unknown exception \n";
        return 2;
    }


}
