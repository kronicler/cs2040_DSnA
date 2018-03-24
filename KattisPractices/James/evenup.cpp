#include <iostream>
#include <list>
using namespace std;

int main () {
	int num, x;
	list <int> l1, temp;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> x;
		l1.push_back(x);
	}

	while (!l1.empty()) {
		temp.push_back(l1.front());
		l1.pop_front();
		if (l1.empty()) continue;
		if ((temp.back()+l1.front())%2 == 0) {
			temp.pop_back();
			l1.pop_front();
			while (!temp.empty()) {
				l1.push_front(temp.back());
				temp.pop_back();
			}
		}
	}
	cout << temp.size() << endl;
	return 0;
}