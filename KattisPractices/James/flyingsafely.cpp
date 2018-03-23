#include <iostream>
using namespace std;

int main () {
	int cases, cities, pilots;
	int a, b;

	cin >> cases;
	while(cases--) {
		cin >> cities >> pilots;
		for (int i = 0; i < pilots; i++) cin >> a >> b;
		cout << cities-1 << endl;
	}
	return 0;
}