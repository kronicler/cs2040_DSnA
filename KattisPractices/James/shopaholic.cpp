#include <bits/stdc++.h>
using namespace std;

int main () {
	long long elements, x, sum = 0;
	vector <long long> vect;
	cin >> elements;
	for (int i = 0; i < elements; i++) {
		cin >> x;
		vect.push_back(x);
	}

	sort(vect.begin(), vect.end(), [](long long a, long long b) {return a > b;});
	for (int i = 2; i < elements; i += 3) sum += vect[i];

	cout << sum << endl;
	return 0;
}