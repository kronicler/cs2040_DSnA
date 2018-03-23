#include <iostream>
#include <string>
using namespace std;

int main () {
	int pile1, pile2, plates;
	int test;
	string command;
	while (1) {
		cin >> test;
		if (!test) break;
		pile1 = pile2 = 0;
		for (int i = 0; i < test; i++) {
			cin >> command >> plates;

			if (command == "DROP") {
				pile2 += plates;
				cout << "DROP 2 " << plates << endl;
			} else if (command == "TAKE") {
				if (!pile1) {
					cout << "MOVE 2->1 " << pile2 << endl;
					cout << "TAKE 1 " << plates << endl;
					pile1 += pile2;
					pile1 -= plates;
					pile2 = 0;
				} else if (pile1 < plates) {
					cout << "TAKE 1 " << pile1 << endl;
					cout << "MOVE 2->1 " << pile2 << endl;
					cout << "TAKE 1 " << plates-pile1 << endl;
					pile1 = pile2-(plates-pile1);
					pile2 = 0;
				} else {
					cout << "TAKE 1 " << plates << endl;
					pile1 -= plates;
				}
			}
		}
		cout << endl;
	}
	return 0;
}