#include <iostream>
#include <cstdlib>

using namespace std;

int main () {
	int numRooms, taken[100];
	int i, booked, random, flag;

	cin >> numRooms >> booked;

	for (i = 0; i < booked; i++) {
		cin >> taken[i];
	}

	if (numRooms == booked) {
		cout << "too late" << endl;
	} else {
		do {	
			flag = 1;
			random = (rand()%numRooms) + 1;
			for (i = 0; i < booked; i++) {
				if (random == taken[i]) flag = 0;
			}
		} while (flag == 0);
		cout << random << endl;
	}

	return 0;
}
