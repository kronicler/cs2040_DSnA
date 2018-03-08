#include <bits/stdc++.h>
using namespace std;
unordered_map <int, set<int>> edgelist;
int main(int argc, char** argv) {
	int houses,cables;
	cin >> houses >> cables;
	for(int i = 0; i < cables; i++ ){
		int v1,v2;
		cin >> v1 >>v2;
		edgelist[v1].insert(v2);
		edgelist[v2].insert(v1);	
	}
	stack<int> unexplored;
	unexplored.push(1);
	unordered_set<int> explored;
	explored.insert(1);
	while(!unexplored.empty()){
		auto neighbours = edgelist[unexplored.top()];
		unexplored.pop();
		for(auto n:neighbours){
			if(explored.find(n) == explored.end()){
				unexplored.push(n);
				explored.insert(n);
			}
		} 
	}
	if(explored.size() == houses) cout << "Connected" <<endl;
	else{
		for(int i = 1 ; i <= houses; i++){
			if(explored.find(i) == explored.end()){
				cout << i << endl;
			}
		} 
	}
}
