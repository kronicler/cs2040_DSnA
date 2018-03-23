#include <iostream>
using namespace std;

double computeAverage(int row, int num, int data[][1000]) {
	int sum = 0;
	for (int i = 0; i < num; i++) {
		sum += data[row][i];
	}
	return (double)(sum/num);
}

int main() {
	int testCases, numData, count;
	double ave, percentage;

	cin >> testCases;
	int data[testCases][1000];

	for (int i = 0; i < testCases; i++) {
		cin >> numData;
		count = 0;
		for (int j = 0; j < numData; j++) {
			cin >> data[i][j];
		}
		ave = computeAverage(i, numData, data);
		for (int j = 0; j < numData; j++) {
			if (data[i][j] > ave) count++;
		}
		percentage = ((double)count/numData)*100;
		printf("%.3lf%%\n", percentage);
	}
	
	return 0;
}