#include <iostream>
#include <string>
using namespace std;
int main(){
	string input,output;
	cin >> input;
	char prev_l = 0;
	for(int i = 0; i < input.size(); i++){
		if(input[i] != prev_l){
			prev_l = input[i];
			output += input[i];
		}
	}
	cout << output << endl;
}
