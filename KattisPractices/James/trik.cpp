#include <iostream>
using namespace std;

int main () {
	string input;
	cin >> input;
	int pos[3] = {1,0,0};
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'A') swap(pos[0],pos[1]);
		else if (input[i] == 'B') swap(pos[1],pos[2]);
		else swap(pos[0],pos[2]);
	}

	for (int i = 0; i < 3; i++)
		if(pos[i] == 1) cout << i+1 << endl;

	return 0;
}
