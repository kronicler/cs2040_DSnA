#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	int n, x;

	cin >> n;
	int p[n];
	for (int i = 0; i < n; i++) {
		cin >> x;
		p[i] = x;
	}

	sort(p, p+n, [](int a, int b){return a > b;});
	
	int alice = 0, bob = 0;
	for (int i = 0; i < n; i++) {
		if (i%2) bob += p[i];
		else alice += p[i]; 
	}

	cout << alice << " " << bob << endl;

	return 0;
}