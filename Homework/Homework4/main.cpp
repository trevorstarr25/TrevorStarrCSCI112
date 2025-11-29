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
        else{
            cout << "Invalid token " << token << endl;
            return NAN;
        }
    }

    if(s.size() != 1){
        cout << "Invalid expression: too many operands" << endl;
        return NAN;
    }

    return s.pop();
}

int main(int argc, char *argv[])
{
    if(argc == 3 && string(argv[1]) == "-p"){
        double result = evaluateRPN(argv[2]);
        cout << argv[2] << " = " << result << endl;
        return 0;
    }

    string input;
    cout << "Enter an RPN expression: ";
    getline(cin, input);

    double result = evaluateRPN(input);
    cout << input << " = " << result << endl;

    return 0;
}
