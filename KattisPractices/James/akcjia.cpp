#include <iostream>
#include <vector>
using namespace std;

int main () {
	int books, sum = 0, x;
	vector<int> bought;
	cin >> books;	
	while (books--) {
		cin >> x;
		bought.push_back(x);
	}
	sort(bought.begin(), bought.end());

	int count = 1;
	for (int i = bought.size()-1; i >= 0; i--) {
		if (count == 3) {
			count = 0;
			bought[i] = 0;
		}
		count++;
	}

	for (auto &it : bought)
		sum += it;

	cout << sum << endl;
	return 0;
}