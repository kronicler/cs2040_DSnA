#include <iostream>
#include <vector>
using namespace std;

int main () {
	int elements;
	int count = 0;
	long min, max;
	
	cin >> elements;
	long input[elements], rightMin[elements], leftMax[elements];
	for (int i = 0; i < elements; i++) {
		cin >> input[i];
	}

	max = input[0];
	for (int i = 0; i < elements; i++) {
		if (!i) leftMax[i] = input[i];
		else {
			if (input[i-1] > max) max = input[i-1];
			leftMax[i] = max;
		}
	}

	min = input[elements-1];
	for (int i = elements-1; i >= 0; i--) {
		if (i == elements-1) rightMin[i] = input[i];
		else {
			if (input[i+1] < min) min = input[i+1];
			rightMin[i] = min;
		}
	}
	
	for (int i = 0; i < elements; i++) {
		if ((input[i] >= leftMax[i] && input[i] < rightMin[i]) || (i == elements-1 && input[i] <= rightMin[i] && input[i] >= leftMax[i])) count++;
	}

	cout << count << endl;
	return 0;
}