#include <iostream>
#include <string>
using namespace std;

int main () {
	int test, count = 1;
	int counter;
	while (1) {
		cin >> test;
		if (!test) break;

		string set[test];
		string in;
		counter = 0;
		for (int i = 0; i < test; i++) {
			if (i%2) {
				cin >> set[test-counter-1];
				counter++;
			} else {
				cin >> set[counter];
			}
		}

		cout << "SET " << count << endl;
		count++;
		for (int i = 0; i < test; i++) {
			cout << set[i] << endl;
		}
	}

	return 0;
}