#include <iostream>
using namespace std;

int main () {
	int a, b;

	while (cin >> a >> b, !(!a&&!b)) {
		cout << a/b << " " << a%b << " / " << b << endl;
	}
	return 0;
}