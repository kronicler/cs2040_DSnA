#include <iostream>
using namespace std;

int main () {
	int cases;

	cin >> cases;
	while(cases--) {
		int x;
		cin >> x;
		cout << x;
		if(x%2) cout << " is odd" << endl;
		else cout << " is even" << endl;
	}
	return 0;
}
