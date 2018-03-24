#include <iostream>
using namespace std;

int main () {
	int sweet, sour;

	while (cin >> sweet >> sour, sweet + sour != 0) {
		if (sweet + sour == 13) cout << "Never speak again.\n";
		else if (sweet > sour) cout << "To the convention.\n";
		else if (sour > sweet) cout << "Left beehind.\n";
		else cout << "Undecided.\n";
	}

	return 0;
}