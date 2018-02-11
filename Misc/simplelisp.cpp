#include <iostream>
#include <string>
#include <stack>
using namespace std;


float evaluate_stack(char _operator, stack<float>& values){
	float accum = (_operator=='+'|| _operator == '-')? 0 : 1;
	float v; 
	while(values.size()){
		v = values.top();
		switch(_operator){
			case '+':
				accum += v;
				break;
			case '-':
				accum -= v;
				break;
			case '*':
				accum *= v;
				break;
			case '/':
				accum /= v;
				break;
		}
		values.pop();
	}
	return accum;
}

bool is_operator(char c){
	return c == '-' || c == '*' ||c == '+' ||c=='*';
}

void evaluate_till_prev_brace(stack<string>& _stack){
	stack<float> operands;
	while(!is_operator(_stack.top()[0])){
		operands.push(stof(_stack.top()));
		_stack.pop();
	}
	float res = evaluate_stack(_stack.top()[0],operands);
	_stack.pop();
	_stack.push(to_string(res));	
}
string evaluate_lisp(string sexpr){
	string tmp;
	stack<string> tokens;
	bool expected_operand = false;
	for(int i  = 0; i <sexpr.size(); i++){
		//cout << "checking token" << sexpr[i] <<endl;
		switch(sexpr[i]){
			case '(':
				if(tmp!=""){
					tokens.push(tmp);
					tmp = "";
				}
				expected_operand = true;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				if(!expected_operand) {
					cerr << "Syntax Error! unexpected operand" << sexpr[i] <<endl;
					return "FATAL: Could not parse correctly";
				}
				if(tmp != ""){
					tokens.push(tmp);
					tmp = "";
				}
				tokens.push(tmp+sexpr[i]);
			case ' ':
				if(tmp != ""){
					tokens.push(tmp);
					tmp = "";
				}
				break;
			case ')':
				if(tmp != ""){
					tokens.push(tmp);
					tmp = "";
				}
				evaluate_till_prev_brace(tokens);	
				break;
			default:
				tmp += sexpr[i];	 
		}
	}
	return tokens.top();	
}

int main(int argc, char** argv) {
	string to_be_eval;
	cout << "Simple S-Expression Evaluator for CS2040C tutorial 3" << endl;
	cout << "Tyoe \"exit\" to leave the shell" <<endl<<endl;
	cout << "s-expr eval >> ";
	while(getline(cin, to_be_eval)){
		if(to_be_eval == "exit" ) break;
		else {
			cout << evaluate_lisp(to_be_eval) << endl;
		}
		cout << "s-expr eval >> ";
	}
	return 0;
}
