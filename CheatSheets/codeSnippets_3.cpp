// Dikjstra largest factor algorithm 
void perform_dijkstra (int source, int numv, int dest) {
        // Init a vector of sized numv all with values of 1000000
    vector<long double> added_weight(numv, 1000000);

    // Notice we use a BST instead for this one
    set<pair<long double, int> > q;
    // Init source to 0
    added_weight[source] = 0;
    q.insert(make_pair(0, source));

    while (!q.empty()) {
        int current = q.begin()->second;
        q.erase(q.begin());

        for (auto it = AL[current].begin(); it != AL[current].end(); it++) {

            // Relax
            int v = it->second;
            long double weight_curr = added_weight[current];

            // -log10 for larger factor when fraction is smaller
            if (added_weight[v] > weight_curr + -log10(it->first)) {
                added_weight[v] = weight_curr + -log10(it->first);
                q.insert(make_pair(added_weight[v], it->second));
            }
        }
    }
    return added_weight[dest];
}


// Floyd warshall algo
// Time complexity: O(V^3) constant
void floydWarshall (int graph[][V])
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    int dist[V][V], i, j, k;

    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
        for (k = 0; k < V; k++)
        {
        // Pick all vertices as source one by one
            for (i = 0; i < V; i++)
            {
            // Pick all vertices as destination for the
            // above picked source
                for (j = 0; j < V; j++)
                {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    // Print the shortest distance matrix
        printSolution(dist);
    }


// Dijkstra on a grid mtx where you have to derive your own weights 

    void perform_dijkstra (char mtx[][20], int row, int col) {
        int direction_mtx[row][col];
        int addedweights[row][col];
        for (int i = 0; i < row; i++) {
            for (int d = 0; d < col; d++) {
                direction_mtx[i][d] = -1;
            addedweights[i][d] = 1000000; // inf
        }
    }
    
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int , int> > >, greater<>> q;
    direction_mtx[0][0] = 1; // Robot's initial direction is facing west
    addedweights[0][0] = 0;
    q.push(make_pair(0, make_pair(0, 0)));
    while (!q.empty()) {
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};
        pair<int, pair<int, int>> curr = q.top();
        q.pop();
        int curr_x = curr.second.first;
        int curr_y = curr.second.second;
        for (int i = 0; i < 4; i++) {
            if (curr_x + dx[i] >= 0 && curr_x + dx[i] < col && curr_y + dy[i] >= 0 && curr_y + dy[i] < row) {
                // Termination conditions: if node is visited before, if node is an obstacle
                if (direction_mtx[curr_y + dy[i]][curr_x + dx[i]] > -1) continue;
                if (mtx[curr_y + dy[i]][curr_x + dx[i]] == '#') continue;
                // Constraint, robot can only rotate rightwards
                int rotation = 0;
                if (i > direction_mtx[curr_y][curr_x]) rotation = i - direction_mtx[curr_y][curr_x];
                else if (i < direction_mtx[curr_y][curr_x]) rotation = (4 - direction_mtx[curr_y][curr_x]) + i;
                
                if (addedweights[curr_y + dy[i]][curr_x + dx[i]] > addedweights[curr_y][curr_x] + rotation*2 + 3) {
                    direction_mtx[curr_y + dy[i]][curr_x + dx[i]] = i;
                    addedweights[curr_y + dy[i]][curr_x + dx[i]] = addedweights[curr_y][curr_x] + rotation*2 + 3;
                    q.push(make_pair(addedweights[curr_y][curr_x] + abs(i - direction_mtx[curr_y][curr_x])*2 + 3,
                       make_pair(curr_x + dx[i], curr_y + dy[i])));
                }
            }
        }
    }
    
    cout << addedweights[row-1][col-1] << endl;
    
}


// DFS/ BFS with limits
list<int> AL[10];
unordered_set<int> visited;
int limit;

void dfs (int v, int dist) {
    if (visited.find(v) != visited.end()) return;
    if (dist >= limit) return;
    visited.insert(v);

    for (auto it : AL[v])
    {
        dfs(v, dist + 1);
    }
}

void bfs (int v, int limits) {
    queue<pair<int, int> > q;
    q.push(make_pair(v, 0));

    while(!q.empty()) {
        pair<int, int> curr = q.front();

        if (curr.second >= limit) continue;

        visited.insert(curr.first);

        for (auto it : AL[curr.first])
        {
            if (visited.find(it) == visited.end()) 
                q.push(make_pair(it, curr.second + 1));
        }
    }
}


// Bipartite checker
// O (V(V + E))
void Bipartite_checker_wilson (list<int> AL[], int v) {
    for (int i = 0; i < v; i++) {
        unordered_map<int, int> colouring;
        // Check by colouring the graph and see if it reaches the same colour twice
        queue<int> q;
        q.push(i);
        colouring[i] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it : AL[curr]) {
                if (colouring.find(it) == colouring.end() && colouring[curr] == 1) {
                    colouring[it] = 2;
                    q.push(it);
                }
                else if (colouring.find(it) == colouring.end() && colouring[curr] == 2) {
                    colouring[it] = 1;
                    q.push(it);
                }
                else if (colouring[it] == colouring[curr]) {
                    cout << "not bipartite" << endl;
                    return;
                }
            }
        }
    }
}

void Bipartite_checker (int v, list<int> AL[]) {
    vector<int> colouring (v, -1);

    // This is to handle disconnected graphs
    for (int i = 0; i < v; i++) {
        // We only initate the BFS when its not been coloured before
        if (colouring[i] == -1) {
            queue<int> q;
            q.push(i);
            // Only assign a colour when it doesnt have one
            colouring[i] = 1;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (auto it : AL[curr]) {
                    if (colouring[it] == -1) {
                        colouring[it] = 1 - colouring[curr];
                        q.push(it);
                    }else if (colouring[it] == colouring[curr]) {
                        // If colouring of current is the same as its neighbours, means its not bipartite 
                        cout << "non bipartite" << endl;
                        return;
                    }
                }
            }
        }
    }

}


// BFS to find shortest path in a maze/ grid 
// O (V + E) (faster than dijkstra as no operations needed to extract from a pq)

// Assuming grid size is 10 by 10
void bfs_maze (char grid[10][10], pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int> > q;
    q.push(start);
    vector<vector<int> > added_weights(10, vector<int> (10, 100000));
    
    added_weights[start.second][start.first] = 0;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int dx [4] = {0,1,0,-1};
        int dy [4] = {1,0,-1,0};
        for (int i = 0; i < 4; i++) {
            if (curr.first + dx[i] < 10 && curr.first + dx[i] >= 0 && curr.second + dy[i] >= 0 && curr.second + dy[i] < 10) {
                // If it is an obstable, ignore everything
                if (mtx[curr.second + dy[i]][curr.first + dx[i]] == '#' ) continue;
                
                if (added_weights[curr.second + dy[i]][curr.first + dx[i]] == 100000) {
                    // unvisited and not an obstable
                    if (added_weights[curr.second + dy[i]][curr.first + dx[i]] > added_weights[curr.second][curr.first] + 1) {
                        // Relax
                        added_weights[curr.second + dy[i]][curr.first + dx[i]] = added_weights[curr.second][curr.first] + 1;
                        q.push(make_pair(curr.first + dx[i], curr.second + dy[i]));
                    }
                }
            }
        }
    }
    
    for (auto it : added_weights) {
        for (auto it2 : it) {
            if (it2 == 100000) cout << "INF";
            else cout << it2;
            cout << "\t";
        }
        cout << endl;
    }

    cout << added_weights[end.second][end.first] << endl;
}
// Input: 
/*
..........
..........
.s........
......e...
..........
##########
..........
..........
..........
..........
*/

// Output: 
/*
3   2   3   4   5   6   7   8   9   10  
2   1   2   3   4   5   6   7   8   9   
1   0   1   2   3   4   5   6   7   8   
2   1   2   3   4   5   6   7   8   9   
3   2   3   4   5   6   7   8   9   10  
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF 
INF INF INF INF INF INF INF INF INF INF     
*/


// Topo sort DFS + One pass bellman ford - find longest path (DAG)
// O (V + 2E)
list<pair<int, int> > AL[10000];

void DFS_recur (int vertex, unordered_map<int, int> *visited, list<int> * topo_list) {
    // Mark visited
    visited->insert(make_pair(vertex, 1));
    // Show its visits
    for (auto it : AL[vertex]) {
        if (visited->find(it.second) == visited->end()) {
            DFS_recur(it.second, visited, topo_list);
        }
    }
    // Finish DFS, add to back of list
    topo_list->push_back(vertex);
}

list<int> topo_sort_dfs (int v) {
    list<int> topo;
    unordered_map<int, int> visited;
    DFS_recur(v, &visited, &topo);
    topo.reverse();
    return topo;
}

void one_pass (list<int> sorted, int V) {
    vector<int> added_weights (V, -100000); // We use negative INF instead
    added_weights[0] = 0;
    
    for (auto curr : sorted) {
        for (auto it2 : AL[curr]) {
            // To find the max of combined weights
            if (added_weights[it2.second] < added_weights[curr] + it2.first) {
                added_weights[it2.second] = added_weights[curr] + it2.first;
            }
        }
    }
}


// Next permutation
void permutation () {
    int arr[5] = {1,2,3,4,5};
    
    int count = 0;
    while (next_permutation(arr, arr + 5)) {
        for (auto it :  arr) {
            cout << it << " ";
        }
        cout << endl;
        count++;
    }
    // Will output every permutation of this array 
    cout << count << endl; // Total permutation = 120 (5P5)
}


// Partial sort 
int main () {
    vector<int> myints ({5,4,3,2,1,1,2,3});
    
    partial_sort(myints.begin(), myints.begin()+ 2, myints.end());
    for (auto it : myints) {
        cout << it << " ";
    }
    cout << endl;
    // Output: 1 1 5 4 3 2 2 3
    // Only the first 2 elements got sorted and swapped
    
    /////////////////////////////////////////////////////////////
    sort(myints.begin(), myints.begin() + 2);
    for (auto it : myints) {
        cout << it << " ";
    }
    cout << endl;
    // Output: 4 5 3 2 1 1 2 3
    // Only the first 2 elements got sorted without taking into account the entire array
}



// Water jug problem 
void bfs_everchanging (int target, int a, int b, int c) {
    tuple<int, int, int> initial ({0,0,0});
    set<tuple<int, int, int> > visited;
    queue<tuple<int, int, int> > q;
    map<tuple<int, int, int>, int> steps;
    steps[initial] = 0;
    q.push(initial);
    
    while (!q.empty()) {
        tuple<int, int, int> curr = q.front();
        q.pop();
        visited.insert(curr);
        int curr_a = get<0>(curr);
        int curr_b = get<1>(curr);
        int curr_c = get<2>(curr);
        
        int da[12] =  {0, curr_a, curr_a, a, curr_a, curr_a, curr_a-curr_b, curr_b+curr_a, curr_a-curr_c, curr_c+curr_a, curr_a, curr_a};
        int db[12] =  {curr_b, 0, curr_b, curr_b, b, curr_b, curr_a+curr_b, curr_b-curr_a, curr_b, curr_b, curr_b-curr_c, curr_c+curr_b};
        int dc[12] =  {curr_c, curr_c, 0, curr_c, curr_c, c, curr_c, curr_c, curr_a+curr_c, curr_c-curr_a, curr_b+curr_c, curr_c-curr_b};
        
        // Focal point: Nodes were not defined at the start, they were defined only while it is BFS-ing. This allows for an expanding graph of possibilities
        // Wont run into infinite loop as we have a visited set to keep track.
        for (int i = 0; i < 12; i++) {
            // Duplication point        
            if (i == 6){
                if (da[i] < 0 && db[i] > b) {
                    da[i] = db[i]-b;
                } else if (da[i] < 0) {
                    db[i] += da[i];
                    da[i] = 0;
                } else if (db[i] > b) {
                    da[i] = db[i] - b;
                    db[i] = b;
                }
            }
            // Now write the rest for the transfer of other jugs....


            tuple<int, int, int> modified ({da[i], db[i], dc[i]});
            if (visited.find(modified) == visited.end()) {
                q.push(modified);
                steps[modified] = steps[curr] + 1;
            }else if (steps[modified] > steps[curr] + 1) {
                q.push(modified);
                steps[modified] = steps[curr] + 1;
            }

        }

    }
    // Search and find those with a == d and print out the one with the smallest steps[].
    // If visited set does not conntain any tuple with a == d, means its not possible 
}

