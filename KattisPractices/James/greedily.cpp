#include <iostream>
#include <vector>
using namespace std;

int main () {
	int items;
	int x;
	cin >> items;
	vector <int> out;

	int prev = -1;
	int count = 0;
	for (int i = 0; i < items; i++) {
		cin >> x;
		if (x > prev) {
			out.push_back(x);
			count++;
			prev = x;
		}
	}

	cout << count << endl;
	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	} cout << endl;
	return 0;
}
