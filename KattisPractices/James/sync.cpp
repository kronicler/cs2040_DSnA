#include <bits/stdc++.h>
using namespace std;

int main () {
	vector <int> list1, list2, copy1;

	while (1) {
		int test, input;
		list1.clear();
		list2.clear();
		copy1.clear();
		
		cin >> test;
		if (!test) break;
		for (int i = 0; i < test; i++) {
			cin >> input;
			list1.push_back(input);
		}
		for (int i = 0; i < test; i++) {
			cin >> input;
			list2.push_back(input);
		}

		copy1 = list1;
		sort(copy1.begin(), copy1.end());
		sort(list2.begin(), list2.end());
		for (int i = 0; i < test; i++) {
			for (int j = 0; j < test; j++) {
				if (list1[i] == copy1[j]) cout << list2[j] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}