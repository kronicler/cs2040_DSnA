#include <bits/stdc++.h>
using namespace std;

int main () {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a + b + c == 0) break;
		vector<int> sides;
		sides.push_back(a);
		sides.push_back(b);
		sides.push_back(c);
		stable_sort(sides.begin(), sides.end());
		if (pow(sides[2],2) == pow(sides[1],2) + pow(sides[0],2)) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
	return 0;
}