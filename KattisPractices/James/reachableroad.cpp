#include <iostream>
#include <vector>
using namespace std;

//Counts the sum (varibale 'counts') of the number of edges in the minimum spanning tree of
//each connected component

//Outputs the difference between the number of edges in the minimum spanning tree
//of all the endpoints and the sum

vector <int> v[1000];
int visited[1000];
int counts;

void dfs(int source) {
	visited[source] = 1;
	for (int i = 0; i < v[source].size(); i++) {
		if (visited[v[source][i]] == 0) {
			counts++;
			dfs(v[source][i]);
		}
	}
}

int main () {
	int cities, endpoints, r, a, b;

	cin >> cities;
	while (cities--) {
		for (auto& i : v) i.clear();
		for (int i = 0; i < 1000; i++) visited[i] = 0;
		
		counts = 0;
		cin >> endpoints;
		cin >> r;

		for (int i = 0; i < r; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 0; i < endpoints; i++) if (!visited[i]) dfs(i);

		cout << endpoints-1-counts << endl;
	}
	return 0;
}