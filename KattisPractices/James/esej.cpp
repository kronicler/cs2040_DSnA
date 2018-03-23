#include <iostream>
using namespace std;

int main () {
	int a, b, min, count = 0;
	cin >> a >> b;
	min = max(a, b/2 + 1);

	for (int i = 'a'; i <= 'z'; i++) {
		for (int j = 'a'; j <= 'z'; j++) {
			for (int k = 'a'; k <= 'z'; k++) {
				for (int l = 'a'; l <= 'z'; l++) {
					cout <<(char)i<<(char)j<<(char)k<<(char)l<<" ";
					count++;
					if (count == min) {
						cout << endl;
						return 0;
					}
				}
			}
		}
	}
}