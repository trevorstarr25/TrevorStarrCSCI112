#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

double evaluateRPN(string expression)
{
    Stack s;
    stringstream ss(expression);
    string token;

    while(ss >> token){
        if(isdigit(token[0]) || ((token[0] == '-' || token[0] == '+') && token.size() > 1)){
            s.push(stod(token));
        }
        else if(token == "+" || token == "-" || token == "*" || token == "/"){
            if(s.size() < 2){
                cout << "Invalid expression." << endl;
                return NAN;
            }
            
            //for first op.
            double b = s.pop();
            //for second op
            double a = s.pop();

            if(token == "+")         s.push(a + b);
            else if(token == "-")    s.push(a - b);
            else if(token == "*")    s.push(a * b);
            else if(token =="/"){
                if(b == 0){
                    cout << "Error: division by zero" << endl;
                    return NAN;
                }
                s.push(a / b);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    return 0;
}
