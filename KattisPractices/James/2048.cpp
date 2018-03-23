#include <iostream>
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3
using namespace std;

void printOutput (int output[][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << output[i][j] << ' ';
		}
		cout << endl;
	}
}

void moveInput(int input[][4], int direction) {
	int output[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			output[i][j] = input[i][j];
		}
	}

	if (direction == LEFT) {
		for (int i = 0; i < 4; i++) {
			for (int k = 1; k < 4; k++) {
				for (int j = k; j > 0; j--) {
					if (input[i][j-1] == 0) {
						input[i][j-1] = input[i][j];
						input[i][j] = 0;
						output[i][j-1] = input[i][j-1];
						output[i][j] = 0;
					} else if (input[i][j-1] == input[i][j]) {
						output[i][j-1] = input[i][j]*2;
						input[i][j-1] = 0-j;
						output[i][j] = 0;
						input[i][j] = 0;
					}
				}
			}
		}
	} else if (direction == UP) {
		for (int j = 0; j < 4; j++) {
			for (int k = 1; k < 4; k++) {
				for (int i = k; i > 0; i--) {
					if (input[i-1][j] == 0) {
						input[i-1][j] = input[i][j];
						input[i][j] = 0;
						output[i-1][j] = input[i-1][j];
						output[i][j] = 0;
					} else if (input[i-1][j] == input[i][j]) {
						output[i-1][j] = input[i][j]*2;
						input[i-1][j] = 0-i;
						output[i][j] = 0;
						input[i][j] = 0;
					}
				}
			}
		}
	} else if (direction == RIGHT) {
		for (int i = 0; i < 4; i++) {
			for (int k = 3; k >= 0; k--) {
				for (int j = k; j < 3; j++) {
					if (input[i][j+1] == 0) {
						input[i][j+1] = input[i][j];
						input[i][j] = 0;
						output[i][j+1] = input[i][j+1];
						output[i][j] = 0;
					} else if (input[i][j+1] == input[i][j]) {
						output[i][j+1] = input[i][j]*2;
						input[i][j+1] = 0-j;
						output[i][j] = 0;
						input[i][j] = 0;
					}
				}
			}
		}
	} else if (direction == DOWN) {
		for (int j = 0; j < 4; j++) {
			for (int k = 3; k >= 0; k--) {
				for (int i = k; i < 3; i++) {
					if (input[i+1][j] == 0) {
						input[i+1][j] = input[i][j];
						input[i][j] = 0;
						output[i+1][j] = input[i+1][j];
						output[i][j] = 0;
					} else if (input[i+1][j] == input[i][j]) {
						output[i+1][j] = input[i][j]*2;
						input[i+1][j] = 0-i;
						output[i][j] = 0;
						input[i][j] = 0;
					}
				}
			}
		}
	}

	printOutput(output);
}

int main () {
	int input[4][4];
	int direction;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> input[i][j];
		}
	}
	cin >> direction;
	moveInput(input, direction);

	return 0;
}