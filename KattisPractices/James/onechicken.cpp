#include <iostream>
using namespace std;

int main () {
	int peeps, chicks;

	cin >> peeps >> chicks;

	if (peeps - chicks <= 0) {
		cout << "Dr. Chaz will have " << (chicks-peeps);
		if (chicks-peeps > 1) cout << " pieces ";
		else cout << " piece ";
		cout << "of chicken left over!\n";
	} else {
		cout << "Dr. Chaz needs " << (peeps-chicks);
		if (peeps-chicks > 1) cout << " more pieces ";
		else cout << " more piece ";
		cout << "of chicken!\n";
	}

	return 0;
}
