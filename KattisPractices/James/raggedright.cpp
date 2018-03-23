#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
	vector<string> line;
	string in;
	int max = -1, sum = 0;

	while (getline(cin, in)) {
		if ((int)in.length() > max) max = (int)in.length();
		line.push_back(in);
	}

	for (auto it = line.begin(); it != line.end()-1; it++) sum += pow(max - (int)it->length(), 2);
	cout << sum << endl;
	return 0;
}