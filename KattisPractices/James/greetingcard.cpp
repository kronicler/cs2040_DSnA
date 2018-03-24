#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

ll total(set<pll> &s, pll point) {
	int count = 0;
	vector<pll> vect;

	vect.push_back({point.first + 2018, point.second});
	vect.push_back({point.first, point.second + 2018});

	vect.push_back({point.first, point.second - 2018});
	vect.push_back({point.first - 2018, point.second});

	vect.push_back({point.first + 1680, point.second + 1118});
	vect.push_back({point.first + 1118, point.second + 1680});

	vect.push_back({point.first + 1118, point.second - 1680});
	vect.push_back({point.first - 1680, point.second + 1118});

	vect.push_back({point.first + 1680, point.second - 1118});
	vect.push_back({point.first - 1118, point.second + 1680});

	vect.push_back({point.first - 1118, point.second - 1680});
	vect.push_back({point.first - 1680, point.second - 1118});

	for (auto it : vect)
		if (s.count(it) > 0) count++;

	return count;
}

int main () {
	int points;
	ll sum = 0;
	pll p;
	vector<pll> vect;
	set<pll> s;

	cin >> points;
	while (points--) {
		cin >> p.first >> p.second;
		vect.push_back(p);
		s.insert(p);
	}
	sort(vect.begin(), vect.end());

	for (auto it : vect) {
		sum += total(s, it);
		s.erase(it);
	}

	cout << sum << endl;

	return 0;
}