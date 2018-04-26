#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#define INF 1000000000
using namespace std;

// write your matric number here: A0177603A
// write your name here: Aaryam Srivastava
// write list of collaborators here: n/a
// year 2017 Sem2 hash code: WxxVfOfqw6Be7Cyq2acb (do NOT delete this line)

typedef pair<int, int> ii;
int V;
int Q;
vector<vector<ii>> AdjList;
// A 2D array to represent the shortest paths to every other node from every single possible source
vector<vector<int>> source_weight;

int Query(int s, int t, int k) {
    int ans = -1;
    if (source_weight[s][t] != INF) ans = source_weight[s][t];
    return ans;
}

//I used djikstra's algorithm to pre-calculate all of the shortest paths to every single node
//from every possible source node
void Djikstra() {
    //clear the 2D array each time for a new test case
    source_weight.assign(min(V,10), vector<int>());
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    //perform Djikstra's algorithm for every single source, which is calculated by min(V, 1000) as there
    // are potentially 1000 different sources
    for (int i = 0; i < min(V,10); i++) {
        source_weight[i].assign(V, INF);
        source_weight[i][i] = 0; pq.push(ii(0,i));
        //standard djikstra's algorithm
        while (!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int d = front.first, u = front.second;
            //if statement for time efficiency
            if (d > source_weight[i][u]) continue;
            for (auto &j : AdjList[u]) {
                ii v = j;
                if (source_weight[i][u] + v.second < source_weight[i][v.first]) {
                    source_weight[i][v.first] = source_weight[i][u] + v.second;
                    pq.push(ii(source_weight[i][v.first], v.first));
                }
            }
        }
    }
    
    //debugging code
    /*for (int i = 0; i < V; i++) {
     for (int d = 0; d < V; d++) {
     if (source_weight[i][d] == INF) cout << "INF\t";
     else cout << source_weight[i][d] << "\t";
     }
     cout << endl;
     } */
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int TC; cin >> TC;
    
    while (TC--) {
        int j, k, w;
        cin >> V;
        // clear the graph and read in a new graph as Adjacency List
        AdjList.assign(V, vector<ii>());
        for (int i = 0; i < V; i++) {
            cin >> k;
            while (k--) {
                cin >> j >> w;
                AdjList[i].emplace_back(j, w); // edge (road) weight (in minutes) is stored here
            }
        }
        //perform Djikstra for every single source
        Djikstra();
        int source, destination, required_k;
        cin >> Q;
        //simply output result from the 2D array in O(1)
        while (Q--) {
            cin >> source >> destination >> required_k;
            cout << Query(source, destination, required_k) << endl;
        }
        if (TC) cout << endl;
    }
    return 0;
}
