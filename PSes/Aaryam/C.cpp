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
//2D array contains all of the possible distances from a particular source to any other node
//ROWS of the array contain the number of possible JUNCTIONS while the COLUMNS represent
//the different nodes contained within the graph. The values of the 2D array represent the
//distances from the source to a particular node, using 'k' number of junctions; 1 <= k <= min(V,20)
vector<vector<int>> source_weight;

//Uses a modification of Bellman Ford's algorithm
int Query(int s, int t, int k) {
    // clear the graph each time a new query is made
    source_weight.assign(V, vector<int>(V));
    
    //set all the cells in the 2D array to INF
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < V; j++) {
            source_weight[i][j] = INF;
        }
    }
    //distance from source to source is 0
    source_weight[0][s] = 0;
    
    //perform relaxation operation V-1 times to find all possible paths to each dest node
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < V; j++) {
            int curr = j;
            //calculate all possible paths for each neighbour of each node
            for (int k = 0; k < (int)AdjList[curr].size(); k++) {
                ii curr1 = AdjList[curr][k];
                int vertex = curr1.first;
                int weight = curr1.second;
                
                //relax the edge if possible
                if (source_weight[i][vertex] > source_weight[i-1][curr] + weight) {
                    source_weight[i][vertex] = source_weight[i-1][curr] + weight;
                }
            }
        }
        
        //this is the modification in the algorithm, if a path takes less time with fewer nodes,
        //we accept that path and reject the path with greater nodes traversed
        for (int l = 0; l < V; l++) {
            if (source_weight[i][l] > source_weight[i-1][l]) {
                source_weight[i][l] = source_weight[i-1][l];
            }
        }
    }
    
    int ans;
    //check whether destination can be reached or not using just k junctions
    if (source_weight[k-1][t] >= INF) ans = -1;
    else ans = source_weight[k-1][t];
    return ans;
}

/*void Djikstra() {
    //clear the 2D array each time for a new test case
    source_weight.assign(min(V,1000), vector<int>());
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < min(V,1000); i++) {
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
    } */

/*void print() {
  for (int i = 0; i < V; i++) {
     for (int d = 0; d < V; d++) {
         if (source_weight[i][d] == INF) cout << "INF\t";
         else cout << source_weight[i][d] << "\t";
         }
     cout << endl;
 }
} */

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
        int source, destination, required_k;
        cin >> Q;
        while (Q--) {
            //each time a query is called, perform bellman ford for that particular source point
            //and calculate the correct answer based on the restrictions of required_k
            cin >> source >> destination >> required_k;
            cout << Query(source, destination, required_k) << endl;
        }
        if (TC) cout << endl;
    }
    return 0;
}
