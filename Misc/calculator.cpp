#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <map>

using namespace std;


void calculation (string token, stack<double> *calcStack) {
    if (token[0] <= '9' && token[0] >= '0' ){
        // It is a number
        calcStack->push(stoi(token));
    }else {
        if (token[1] <= '9' && token[1] >= '0') {
            // Negative number
            calcStack->push(stoi(token)); // Stoi works for negative numbers too
            return;
        }
        
        // it is an operator
        double num1, num2;
        num2 = calcStack->top();
        calcStack->pop();
        num1 = calcStack->top();
        calcStack->pop();
        
        if (token == "*") {
            calcStack->push(num1 * num2);
        }
        else if (token == "+"){
            calcStack->push(num1 + num2);
        }
        else if (token == "-") {
            // Order matters for this one too
            calcStack->push(num1 - num2);
        }
        else if (token == "/") {
            // order matters for this one
            calcStack->push(num1 / num2);
        }
    }
}

void processPostFix (string s, string *postfix, stack<string> *opstack) {
    map<string, int> prec;
    prec ["+"] = 1;
    prec ["-"] = 1;
    prec ["*"] = 2;
    prec ["/"] = 2;
    // Check if its a digit first
    if (s[0] <= '9' && s[0] >= '0' ){
        *postfix += s;
        *postfix += " ";
    } else {
        if (s[1] <= '9' && s[1] >= '0') {
            // Negative number
            *postfix += s;
            *postfix += " ";
            return;
        }
        if (opstack->empty()) {
            opstack->push(s);
        } else {
            // Check precedence
            if (s == "(") {
                opstack->push(s);
                return;
            }
            
            if (s == ")") {
                while (opstack->top() != "(") {
                    *postfix += opstack->top();
                    *postfix += " ";
                    opstack->pop();
                }
                opstack->pop();
                return;
            }
            
            if (prec[opstack->top()] > prec[s] || opstack->top() == "(") {
                opstack->push(s);
            } else {
                // popped
                *postfix += opstack->top();
                *postfix += " ";
                opstack->pop();
                opstack->push(s);
            }
        }
    }
}

string postFix (string s) {
    stack<string> opstack;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    string postfix;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        processPostFix(token, &postfix, &opstack);
        s.erase(0, pos + delimiter.length());
    }
    
    //cout << s << endl;
    
    processPostFix(s, &postfix, &opstack);
    
    
    
    while (!opstack.empty()) {
        postfix += opstack.top();
        postfix += " ";
        opstack.pop();
    }
    return postfix;
}

double calculatePostfix (string postfix) {
    string token;
    size_t pos = 0;
    string delimiter = " ";
    stack<double> calculator;

    while ((pos = postfix.find(delimiter)) != string::npos) {
        token = postfix.substr(0, pos);
        
        calculation(token, &calculator);
        postfix.erase(0, pos + delimiter.length());
    }
    
    return calculator.top();
}

int main () {
    // If its higher, it will be stored!
    
    // Process to postfix
    string s;
    getline(cin,s);
    string thisPostfix = postFix(s);
    
    cout << "Postfix: " << thisPostfix << endl;
    cout << "Result: " << calculatePostfix(thisPostfix) << endl;
    
}
