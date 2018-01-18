#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long input, input2;
	cin >> input >> input2;
	while(input != 0 && input2 != 0) {
	    cout << input + input2 << endl;
	    cin >> input >> input2;
	}

	return 0;
}