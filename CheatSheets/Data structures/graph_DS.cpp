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
protected:
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


class sample_topo_sort : adj_list {
    
//Topological sort of a DAG is a linear ordering of the DAG's vertices 
//in which each vertex comes before all vertices to which it has outbound edges.

private:
    unordered_map<int, int> incoming;
    
    void DFS_recur (int vertex, unordered_map<int, int> *visited, list<int> * topo_list) {
        // Mark visited
        visited->insert(make_pair(vertex, 1));
        // Show its visits
        for (auto it = AL[vertex].begin(); it != AL[vertex].end(); it++) {
            // Traverse thru the columns on the same row
            if (visited->find(*it) == visited->end()) {
                // unvisited vertex
                DFS_recur(*it, visited, topo_list);
            }
            // Else skip it
        }
        // Finish DFS, add to back of list
        topo_list->push_back(vertex);
    }

public:
    
    void connect (int v, int v2) {
        AL[v].push_back(v2);
        incoming[v2]++;
    }
    
    sample_topo_sort () : adj_list(10) {
        // Init a sample graph  CP3 4.17 DAG
        // Override
        connect(0, 3);
        connect(0, 1);
        connect(0, 2);
        connect(1, 3);
        connect(1, 4);
        connect(2, 4);
        connect(3, 4);
    }
    
    void topo_sort_dfs (int v) {
        list<int> topo;
        unordered_map<int, int> visited;
        DFS_recur(v, &visited, &topo);
        topo.reverse();
        for (auto it : topo ) {
            cout << it << " ";
        }
        cout << endl;
    }
    
    // Warning: This will delete all your edges
    void topo_sort_bfs (int v) {
        queue<int> Q;
        // Add vertices with no incoming edges to Q
        
        for (int i = 0; i < 5 ; i++) {
            if (incoming.find(i) == incoming.end()) {
                // No incoming edges
                Q.push(i);
            }
        }

        int curr;
        while (!Q.empty()) {
            curr = Q.front(); Q.pop();
            cout << curr << " ";
            for (auto it = AL[curr].begin(); it != AL[curr].end(); it++) {
                AL[curr].erase(it); // Delete the edge
                if (incoming.find(*it) != incoming.end()) incoming[*it]--; // Remove 1 from num incoming for that neighbour
                if (incoming[*it] == 0) Q.push(*it); // If it has no incoming edge, add it to Q
            }
        }
        cout << endl;
    }
};

// TODO: Fill in more theory on graphs like acyclic or special graphs down here.


// Some notes: 
/*
    Bipartite graphs: 
    - A set of vertices seperated into 2 disjoint sets where vertices of the same set are not directly adjacent to each other 

    DAGs: 
    - A graph which is direct and acylic (Warning: it cannot be weighted too)

    Toposort: 
    - Consider all vertices with only outgoing edges first (smallest to largest) - visualgo 
    - Follow same style as BFS topo sort

    Edges that will always be present in min spanning tree:
    - Basically edges to a vertex that cannot be substituted with any other (non cycles, single path)

    Misc: 
    - During BFS/ DFS always go in order of elements (smallest first) in visualgo 
*/


