#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
	string directions = "";
	int n;
	cin >> n;
	if(!cin.eof())
        cin >> directions;
	long res = (long)pow(2,n+1);
	long diff = 1;
	for(int i = 0; i < directions.size() ; i++){
		diff*=2;
		if(directions[i] == 'R') diff++;
	}
	cout << res-diff <<endl;

	return 0;
}
