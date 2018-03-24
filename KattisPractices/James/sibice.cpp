#include <iostream>
#include <math.h>
using namespace std;

int main () {
	int n, w, h, x;

	cin >> n >> w >> h;
	while (n--) {
		cin >> x;
		if (x <= w || x <=h || x <= (double)pow((pow(w,2) + pow(h,2)),0.5)) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
	return 0;
}