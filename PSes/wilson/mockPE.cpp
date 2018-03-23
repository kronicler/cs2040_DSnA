// test_bench.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<long long, int> mymap;

	int N; cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long input;
		cin >> input;
		mymap[input]++;
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long long query; cin >> query;
		if (!query) cout << (prev(mymap.end())->first - mymap.begin()->first) << endl;
		else if (query > 0) {
			mymap[query]++;
		}
		else if (query < 0) {
			if (mymap.find(-1 * query) != mymap.end()) {
				mymap[-1 * query]--;
				if (mymap[-1 * query] == 0) mymap.erase(-1 * query);
			}
		}

	}


    return 0;
}
