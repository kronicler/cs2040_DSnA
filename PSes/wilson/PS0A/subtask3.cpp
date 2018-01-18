#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long number, total = 0;
	int input = 0;
	while (true) {
		char c;
		cin >> number;
		total += number;
		input++;
		if (getchar() == '\n') {
			if (input == 2 && total == 0) {
				break;
			}else {
				cout << total << endl;
				total = 0;
				input = 0;
			}

		}

	}
	return 0;
}