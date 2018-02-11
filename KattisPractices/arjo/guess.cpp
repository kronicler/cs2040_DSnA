#include <string>
#include <iostream>
using namespace std;
int main(int argc, char** argv){
	string response;
	int upper = 1000;
	int lower = 0;
	int guess = 500;
	while(response != "correct"){
		cout << guess <<endl;
		cin >> response;
		if(response == "lower"){ 
			upper = guess-1;
			guess = (lower+guess)/2;
		}
		else if (response == "higher"){ 
			lower = guess+1;
			guess = (upper+lower)/2;
		}
	}
	return 0;
}
