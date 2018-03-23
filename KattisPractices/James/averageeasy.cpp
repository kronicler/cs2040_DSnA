#include <iostream>
#include <stack>
using namespace std;

long double average(int num, int sum) {
	long double result;
	result = (long double)sum/num;
	return result;
}

int main () {
	int testCases, numCS, numE, score, count, sumCS, sumEc;
	stack <int> cS;
	long double aveCS, aveE, newCS, newEC;
	cin >> testCases;

	for (int i = 0; i < testCases; i++) {
		cin >> numCS >> numE;
		count = 0;
		sumCS = sumEc = 0;
		for (int j = 0; j < numCS; j++) {
			cin >> score;
			sumCS += score;
			cS.push(score);
		}
		aveCS = average(numCS, sumCS);
		
		for (int j = 0; j < numE; j++) {
			cin >> score;
			sumEc += score;
		}
		aveE = average(numE, sumEc);

		while (!cS.empty()) {
			newCS = average(numCS-1, sumCS-cS.top());
			newEC = average (numE+1, sumEc+cS.top());
			cS.pop();

			if (newCS > aveCS && newEC > aveE) count++;
		}

		cout << count << endl;
	}
	return 0;
}