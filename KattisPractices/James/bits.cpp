#include <iostream>
#include <cmath>
using namespace std;

int main () {
	int numTest, count, length, ans;
	unsigned long long num, temp;

	cin >> numTest;
	for (int i = 0; i < numTest; i++) {
		cin >> num;
		temp = num;
		length = 0;
		while (temp != 0) {
			temp/=10;
			length++;
		}
		ans = 0;
		for (int j = length-1; j >= 0; j--) {
			count = 0;
			temp = num/pow(10,j);
			while (temp != 0) {
				if(temp%2 == 1) count++;
				temp/=2;
			}
			ans = max(ans,count);
		}
		cout << ans << endl;
	}

	return 0;
}