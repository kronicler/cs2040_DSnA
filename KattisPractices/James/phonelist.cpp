#include <bits/stdc++.h>
using namespace std;

int main () {
	int cases, samples;
	string in;

	cin >> cases;
	while (cases--) {
		set <string> numbers;
		cin >> samples;
		for (int i = 0; i < samples; i++) {
			cin >> in;
			numbers.insert(in);
		}

		int flag = 0;
		string prev = "abc";
		for (auto it : numbers) {
			auto prefix = mismatch(prev.begin(), prev.end(), it.begin());
			if (prefix.first == prev.end()) {
				flag = 1;
				break;
			}
			prev = it;
		}

		if (flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}