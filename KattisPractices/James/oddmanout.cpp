#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int cases, elements, count = 1, oddOne;
	
	cin >> cases;
	while (cases--) {
		int in;
		unordered_map <int, int> uM;
		cin >> elements;
		for (int i = 0; i < elements; i++) {
			cin >> in;
			uM[in]++;
		}

		for (auto it : uM)
				if (it.second == 1)
					oddOne = it.first;
		cout << "Case #" << count++ << ": " << oddOne << endl;
	}
	return 0;
}