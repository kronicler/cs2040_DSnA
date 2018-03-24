#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void test_case (int cases) {
	priority_queue<int> pq;
	queue<int> q;
	stack<int> s;

	int pq_valid = 1, q_valid = 1, s_valid = 1;

	while (cases--) {
		int operation, value;
		cin >> operation >> value;

		if (operation == 1) {
			if (pq_valid) pq.push(value);
			if (q_valid) q.push(value);
			if (s_valid) s.push(value);
		} else {
			if (pq_valid) {
				if (pq.empty() || pq.top() != value) pq_valid = 0;
				else pq.pop();
			}
			if (q_valid) {
				if (q.empty() || q.front() != value) q_valid = 0;
				else q.pop();			
			}
			if (s_valid) {
				if (s.empty() || s.top() != value) s_valid = 0;
				else s.pop();
			}
		}
	}

	int validity = pq_valid + q_valid + s_valid;
	if (!validity) cout << "impossible" << endl;
	else if (validity > 1) cout << "not sure" << endl;
	else {
		if (q_valid) cout << "queue";
		else if (pq_valid) cout << "priority queue";
		else cout << "stack";
	}
	cout << endl;
}

int main () {
	int n;
	while (cin >> n) test_case(n);
	return 0;
}