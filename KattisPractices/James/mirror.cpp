#include <iostream>
using namespace std;

int main () {
	int TC;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		int rows, col;
		cin >> rows >> col;
		char array[rows][col];

		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < col; k++) {
				cin >> array[j][k];
			}
		}

		cout << "Test " << i+1 << endl;
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < col; k++) {
				cout << array[rows-j-1][col-k-1];
			} cout << endl;
		}

	}

	return 0;
}