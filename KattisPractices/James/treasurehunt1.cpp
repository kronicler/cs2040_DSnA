#include <iostream>
using namespace std;

void navigate (int r, int c, char arr[][200]) {
	int i = 0, j = 0, count = 0;
	int l;

	for (l = 0; l < r*c; l++) {
		if (i < 0 || j < 0 || i >= r || j >= c) {
			cout << "Out" << endl;
			break;
		} else if (arr[i][j] == 'T') {
			cout << count << endl;
			break;
		} else if (arr[i][j] == '.') {
			cout << "Lost" << endl;
			break;
		} else {
			count++;
			if (arr[i][j] == 'N') {
				arr[i][j] = '.';
				--i;
			} else if (arr[i][j] == 'S') {
				arr[i][j] = '.';
				++i;
			} else if (arr[i][j] == 'W') {
				arr[i][j] = '.';
				--j;
			} else if (arr[i][j] == 'E') {
				arr[i][j] = '.';
				++j;
			}
		}
	}
}

int main () {
	int r, c, i, j;
	char arr[200][200];

	cin >> r >> c;

	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	navigate(r, c, arr);

	return 0;
}
