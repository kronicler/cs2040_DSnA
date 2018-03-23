#include <iostream>
using namespace std;
int main () {
	int a[5], temp, flag;

	for (i = 0; i < 5; i++) {
		cin >> a[i];
	}

	do {
		flag = 0;
		for (int i = 0; i < 4; i++) {
			if (a[i] > a[i+1]) {
				flag = 1;
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4]);
			}
		}
	} while (flag != 0);

	return 0;
}
