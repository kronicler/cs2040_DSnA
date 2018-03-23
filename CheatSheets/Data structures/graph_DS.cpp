class adj_mtx {
    // Big space complexity of O(V^2)
    
    // Used for quick random access
    
private:
    bool arr[10][10] = {{0}}; // Simple unwieghted adjacency mtx
    // Num rows is also num of vertices
    int numEdges, numV;
    
    // BFS is a queue, DFS is a stack/ implicit stack
    
    void DFS_recur (int vertex, unordered_map<int, int> *visited) {
        // Mark visited
        visited->insert(make_pair(vertex, 1));
        // Show its visits
        cout << vertex << endl;
        for (int i = 0; i < numV; i++) {
            // Traverse thru the columns on the same row
            if (arr[vertex][i] == true && i != vertex) {
                // Connected vertex
                if (visited->find(i) == visited->end()) {
                    // unvisited vertex
                    DFS_recur(i, visited);
                }
            }
        }
    }
    
    void scan_neighbours (queue<int> *q, int vertex, unordered_map<int, int> *visited) {
        for (int i = 0; i < numV; i++) {
            if (arr[vertex][i] == true && visited->find(i) == visited->end()) {
                // Not visited
                visited->insert(make_pair(i, 1));
                q->push(i); // Push the vertices to the queue
            }
        }
    }
    
    
public:
    adj_mtx (int numV) {this->numV = numV;}
    
    void connect (int v, int v2) {
        arr[v][v2] = true;
        arr[v2][v] = true; // Add this to make it undirected
        numEdges++;
    }
    void disconnect (int v, int v2) {
        arr[v][v2] = false;
        arr[v2][v] = false; // Add this to make it undirected
        numEdges--;
    }
    
    bool isConnected (int v, int v2) {
        // O(1)
        return arr[v][v2];
    }
    
    int getEdges () {
        return numEdges;
    }
    int getV () {
        return numV;
    }
    
    void find_neighbour (int v) {
        // Slow - O(N)
        for (int i = 0; i < numV; i++) {
            if (arr[v][i]) {
                cout << i << endl;
            }
        }
    }
    
    void DFS (int vertex) {
        unordered_map<int, int> visited;
        DFS_recur(vertex, &visited);
        // Will create a minimum spanning tree - IE a path thru all vertices with least edges
        // when we backtrack
    }
    
    void BFS (int vertex) {
        unordered_map<int, int> visited;
        queue<int> q;
        int curr = vertex;
        q.push(curr); // Initial push
        visited[curr] = 1; // Mark as visited
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            cout << curr << endl;
            scan_neighbours(&q, curr, &visited);
        }
        
        
    }
    
    void print_mtx () {
        for (int i = 0; i < numV; i++) {
            for (int d = 0; d < numV; d++) {
                cout << arr[i][d] << " ";
            }
            cout << endl;
        }
    }
    
    
};


class adj_list {
    // Space complexity: O(V+E)
private:
    int numV;
    int numEdges;
    list<int> AL[10]; // Push back when we wanna add new adjacent vertices
    // We can also use vector of vectors due to its dynamic properties (ability to push_back)
    
    // Size of array is also num vertices
    
    void DFS_recur (int vertex, unordered_map<int, int> *visited) {
        // Mark visited
        visited->insert(make_pair(vertex, 1));
        // Show its visits
        cout << vertex << endl;
        for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
            // Traverse thru the columns on the same row
            if (visited->find(*it) == visited->end()) {
                // unvisited vertex
                DFS_recur(*it, visited);
            }
        }
    }
    
    void scan_neighbours (queue<int> *q, int vertex, unordered_map<int, int> *visited) {
        for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
            if (visited->find(*it) == visited->end()) {
                visited->insert(make_pair(*it, 1));
                q->push(*it);
            }
        }
    }
    
public:
    adj_list (int numV) {
        this->numV = numV;
    }
    
    void connect (int v, int v2) {
        auto it = find(AL[v].begin(), AL[v].end(), v2);
        if (it == AL[v].end()) {
            AL[v].push_back(v2);
            AL[v2].push_back(v);
            numEdges++;
        }
    }
    
    void disconnect (int v, int v2) {
        auto it = find(AL[v].begin(), AL[v].end(), v2);
        auto it2 = find(AL[v2].begin(), AL[v2].end(), v);
        if (it != AL[v].end()) {
            AL[v].erase(it);
            numEdges--;
        }
        if (it2 != AL[v2].end()) AL[v2].erase(it2);
        // Have to find first then delete
    }
    
    bool isConnected (int v, int v2) {
        // Slower - O(k)
        auto it = find(AL[v].begin(), AL[v].end(), v2);
        if (it != AL[v].end()) return true;
        return false;
    }
    
    int getV () {
        return numV;
    }
    
    int getEdges () {
        return numEdges;
        // We can also get the num of edges by summing up all the sizes of list and then dividing by 2
    }
    void find_neighbour (int v) {
        for (auto it = AL[v].begin(); it != AL[v].end(); it++) {
            cout << *it << endl;
        }
        // Will only traverse as many as number of neighbour the node V has
    }
    
    void DFS (int vertex) {
        unordered_map<int, int> visited;
        DFS_recur(vertex, &visited);
        // Will create a minimum spanning tree - IE a path thru all vertices with least edges
        // when we backtrack
    }
    
    void BFS (int vertex) {
        unordered_map<int, int> visited;
        queue<int> q;
        int curr = vertex;
        q.push(curr); // Initial push
        visited[curr] = 1; // Mark as visited
        while (!q.empty()) {
            curr = q.front();
            q.pop();
            cout << curr << endl;
            scan_neighbours(&q, curr, &visited);
        }
    }
};


class edge_list {
    // Space complexity: O(E)
private:
    set<tuple<int,int,int>> EL; // Normally we store the weights as well to be sorted for algos like Kruskal's algo
    int numV, numEdges;
public:
    edge_list (int numV) {this->numV = numV;}
    
    void connect (int v, int v2, int weight) {
        EL.insert(make_tuple(weight, v, v2)); // Follow the format of weight, v, v2
    }
    
    void disconnect (int v, int v2) {
        for (auto it = EL.begin(); it != EL.end(); it++) {
            if (get<1>(*it) == v && get<2>(*it) == v2) {
                EL.erase(it);
                break;
            }
        }
    }
    
    
};

// TODO: Fill in more theory on graphs like acyclic or special graphs down here.

