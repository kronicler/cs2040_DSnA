// Dikjstra largest factor algorithm 
void perform_djikstra (int source, int numv, int dest) {
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

