#include <iostream>
using namespace std;
int main(){
	int test_cases;
	cin >> test_cases;
	for(int i = 0 ; i < test_cases; i++){
		int dvds;
		cin >> dvds;
		int current_position = 1;
		int moves = 0 ;
		for(int j = 0 ; j < dvds; j++ ) {
			int n;
			cin >> n;
			if(current_position !=n) moves++;
			else current_position++;
		}
		cout << moves <<endl;
	}
}
