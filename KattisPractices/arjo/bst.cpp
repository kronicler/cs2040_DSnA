#include <bits/stdc++.h>
int depth[3000000];
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long c = 0,x;
	set<int> st;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		depth[x] = 0;
		if(st.size() == 0){
			cout << 0 <<endl;
			st.insert(x);
			continue;
		}
		auto parent = st.lower_bound(x);
		if(parent != st.end())
			depth[x] = depth[*parent]+1;
		if(parent != st.begin()){
			parent--;
			depth[x] = max(depth[x],depth[*parent]+1);
		}
		c+=depth[x];
		cout <<c <<endl;
		st.insert(x);	
	}
}
