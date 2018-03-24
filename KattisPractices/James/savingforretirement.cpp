#include <iostream>
using namespace std;

int main () {
	int bob, bobR, bobS, al, alS;
	int alice;
	cin >> bob >> bobR >> bobS >> al >> alS;

	alice = alS;
	int bbb = bobS*(bobR-bob);
	while (alice <= bbb) {
		al++;
		alice += alS;
	}

	cout << al+1 << endl;
	return 0;
}