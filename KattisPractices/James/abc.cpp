#include <iostream>
using namespace std;

int main () {
	int abc[3];
	cin >> abc[0] >> abc[1] >> abc[2];
	sort(abc, abc+3);

	char in;
	for (int i = 0; i < 3; i++) {
		cin >> in;
		if(in == 'A') cout << abc[0];
		else if (in == 'B') cout << abc[1];
		else cout << abc[2];
		cout << " ";
	} cout << endl;
	return 0;
}