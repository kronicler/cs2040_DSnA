#include <iostream>
#include <cstring>
using namespace std;
char input[100010];
int length;
void rshift(int a){
	if(a < 0){
		for (int i = 0; i <length; i++)
			input[i] = input[i-a];
	}
	else {
		for(int i = length-1; i >= 0; i--)
			input[i+a] = input[i];
	}
	length+=a;
}
void process(){
	length = strlen(input);
	int i = length-1;
	if(input[0] == '-'){
		while(i > 0 and input[i] == '9') i--;
		if(i == 0){
			rshift(1);
			input[0] = '-';
			input[1] = '1';
		} else {
			input[i]++;
		}
	}
	else {
		while(i >= 0 and input[i] == '9') i--;
		if(i == 0){
			rshift(1);
			input[0] = '-';
			input[1] += 1;
		}
		else if(i == -1){
			rshift(2);
			input[0] = '-';
			input[1] = '1';
		}
		else {
			input[i]++; 
			while(i > 0 and input[i] == '9') i--;
			if( i == 0||i==-1){
				rshift(1);
				input[0] = '-';
			}
			else{
				input[i] += 1;
				i--;
				while (input[i] == '0') i--;
				input[i] -= 1;
				int sum  = 0;
				for(int j = i+1; j < length; j++) sum += input[j]-'0';
				for(int j = i+1; j < length; j++){
					if(sum <= 9){
						input[j] = sum + '0';
						sum = 0;
					}
					else{
						input[j] = '9';
						sum -= 9;
					}
				}
				if(input[0] == '0') rshift(-1);
			}
		}
	}
	input[length] = 0;
}

int main(){
	int a;
	cin >> a; 
	while(a--){
		cin >> input;
		process();
		cout << input << endl;
	} 
}



