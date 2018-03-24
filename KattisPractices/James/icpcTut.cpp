#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n) {`
	int i = 1;
	while (n != 0) {
		i *= n;
		n--;
	}
	return i;
}
int accepted(unsigned long long m, int n, int type) {
	return 	type == 1? 	(n > 12 || m < factorial(n))? 0 : 1:
			type == 2? 	n <= log2(m):
			type == 3? 	n <= pow (m,0.25):
			type == 4? 	n <= pow (m, 0.33333333333333333333333):
			type == 5? 	n <= pow (m, 0.5):
			type == 6? 	n*log2(n) <= m:
						n <= m;
}

int main () {
	unsigned long long m;
	int n, type;

	cin >> m >> n >> type;

	(accepted(m,n,type))? cout << "AC" << endl : cout << "TLE" << endl;

	return 0;
}