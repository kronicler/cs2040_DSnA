#include <iostream>
using namespace std;

int main () {
	int i, j, n;
	long int min, max, m;
	
	for (i = 1; i <= 10; i++) {
		cin >> n;
		if (feof(stdin))
			break;
		
		max = -1000001;
		min = 1000001;
	
		for (j = 0; j < n; j++) {
			cin >> m;
			if (m < min) min = m;
			if (m > max) max = m;
		}
		cout << "Case " << i << ": " << min << " " << max << " " << max-min << endl;
	}
	
	return 0;
}
