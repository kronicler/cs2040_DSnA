#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int testCases, children;
	unsigned long long sum, in;

	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		cin >> children;
		sum = 0;
		for (int j = 0; j < children; j++) {
			cin >> in;
			sum += in;
			if(sum > children) sum %= children;
		}

		(sum == 0 || sum == children) ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}
