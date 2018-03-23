#include <iostream>
using namespace std;

int main () {
	int cases;
	cin >> cases;
	while (cases--) {
		int a, b;
		cin >> a >> b;

		cout << a << " ";
		cout << (b*(1+b))/2 << " ";
		int n = 1 + 2*(b-1);
		int h = ((n-1)/2+1);
		int ans = (h*(1+n))/2;
		cout << ans << " ";
		n = 2 + 2*(b-1);
		h = ((n-2)/2+1);
		ans = (h*(2+n))/2;
		cout << ans << " " << endl;
	}
	return 0;
}
