#include <bits/stdc++.h>
using namespace std;
int main(int agrc, char** argv){
	priority_queue<tuple<unsigned long long, int, string> > songs;
	int n,r;
	cin >> n >> r;
	for(int i = 0; i < n;i++){
		string name;
		unsigned long long freq;
		cin >> freq >> name;
		songs.push(make_tuple(freq*i,-i,name));
	}
	for(int i = 0; i < r; i++){
		cout << get<2>(songs.top()) <<endl;
		songs.pop();
	}
	return 0;
}
