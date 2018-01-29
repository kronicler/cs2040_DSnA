#include <bits/stdc++.h>

using namespace std;


long int sortFindMed (std::vector<long int> v) {
	if (v.size()%2) {
		// Odd
		return v[v.size()/2];
	}else {
		// Even
		return (v[v.size()/2]+v[v.size()/2-1])/2;
	}
}



int main(int argc, char const *argv[])
{
	int numCase;
	cin >> numCase;
	for (int i = 0; i < numCase; ++i)
	{
		std::vector<long int> v;
		int num;
		long int med = 0;
		cin >> num;
		long int biggest = 0;
		int c = 0;
		for (int d = 0; d < num; ++d)
		{
			long int input;
			cin >> input;
			// Run the insertion loop
			for (c = 0; c < v.size(); c++){
				if (v[c] > input) {
					// Try using a linked list to insert instead 
					v.insert(v.begin()+c, input);
					break;
				} 
			}
			if (c == v.size()) {
				v.push_back(input);
			}


			if (input > biggest) biggest = input;
			med += sortFindMed (v);

		}
		
		cout << med << endl;

	}

	return 0;
}