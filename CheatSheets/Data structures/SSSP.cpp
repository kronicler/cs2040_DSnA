class bellman_ford_graph {
    // Time complexity: O (V * E)
protected:
    list<pair<int, int> > EL[10];
    unordered_map<int, int> added_weight;
    unordered_map<int, int> predecessor;
    int numv;
    
    void relax (int v, int v2, int w) {
        if (added_weight[v2] > added_weight[v] + w) {
            added_weight[v2] = added_weight[v] + w;
            predecessor[v2] = v;
        }
    }
public:
    bellman_ford_graph (int size) {
        this->numv = size;
    }
    
    void connect (int v, int v2, int weight) {
        EL[v].insert(make_pair(weight, v2));
        // This one uses an edge list
        
        // Need to initialise them all to int maximum
        added_weight[v] = INT_MAX;
        added_weight[v2] = INT_MAX;
    }
    
    void bellman_ford () {
        added_weight[0] = 0; // The source should have zero weight
        // Must always start from the source
        for (int i = 0; i < numv; i++) {
            for (auto it = EL[i].begin(); it != EL[i].end(); it++) {
                relax(i, it->second, it->first);
            }
        }
    }
    void get_weight (int v) {
        cout << added_weight[v] << endl;
    }
    // Bellman_ford can be used to detect if there are negative edges too by checking if at least one value in added_weight [v] fails to converge
};


class bfs {
    // Limitations:
    /*
        - All weights must be constant
        - Means can't use on graph with negative edges too
    */
    // Time complexity: O (V + E)
protected:
    list<pair<int, int> > EL[10];
    unordered_map<int, int> added_weight;
    unordered_map<int, int> predecessor;
    int numv;
    
    void relax (int v, int v2, int w) {
        if (added_weight[v2] > added_weight[v] + w) {
            added_weight[v2] = added_weight[v] + w;
            predecessor[v2] = v;
        }
    }
public:
    bfs (int size) {
        this->numv = size;
    }
    
    void connect (int v, int v2, int weight) {
        EL[v].insert(make_pair(weight, v2));
        // This one uses an edge list
        
        // Need to initialise them all to int maximum
        added_weight[v] = INT_MAX;
        added_weight[v2] = INT_MAX;
    }
    
    
    void BFS (int source) {
        queue<int> q;
        q.push(source);
        added_weight[source] = 0;
        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto it = EL[current].begin(); it != EL[current].end(); it++) {
                if (added_weight[it->second] == INT_MAX) {
                    // Unvisited
                    relax(current, it->second, it->first);
                    q.push(it->second);
                }
            }
        }
    }
    
    void get_weight (int v) {
        cout << added_weight[v] << endl;
    }
    
    
    int get_distance (int source, int destination) {
        // Reset all the distances
        for (auto it = added_weight.begin(); it != added_weight.end(); it++) {
            it->second = INT_MAX;
        }
        BFS(source);
        return added_weight[destination];
    }
    
};


class djikstra {
    // Limitations:
    /*
        - Must have no negative edge weights at all
    */
    // Time complexity: O ((V+E) logV)
protected:
    list<pair<int, int> > EL[10];
    unordered_map<int, int> added_weight;
    unordered_map<int, int> predecessor;
    int numv;
    
    
    void relax (int v, int v2, int w) {
        if (added_weight[v2] > added_weight[v] + w) {
            added_weight[v2] = added_weight[v] + w;
            predecessor[v2] = v;
        }
    }
public:
    djikstra (int size) {
        this->numv = size;
    }
    
    void connect (int v, int v2, int weight) {
        EL[v].push_back(make_pair(weight, v2));
        // This one uses an edge list
        
        // Need to initialise them all to int maximum
        added_weight[v] = INT_MAX;
        added_weight[v2] = INT_MAX;
    }
    
    
    void perform_djikstra (int source) {
        priority_queue<pair<int, int> > q;
        // Init source to 0
        added_weight[source] = 0;
        q.push(make_pair(0, source));
        
        while (!q.empty()) {
            int current = q.top().second;
            q.pop();
            for (auto it = EL[current].begin(); it != EL[current].end(); it++) {
                relax(current, it->second, it->first); // Update the added_weights
                // Update PQ - sorta
                // Greedy
                q.push(make_pair(added_weight[it->second], it->second));
            }
        }
    }
    
    void get_weight (int v) {
        cout << added_weight[v] << endl;
    }
    
};


// DFS - can be used for trees only, already O (V + E) because each vertice only has one unique path 



class DP {
    // Limitations:
    /*
        - Only on DAGs
    */
    // Time complexity: O ((V+E))
protected:
    int numv;
    list<pair<int, int>> EL[10];
    unordered_map<int, int> added_weight;
    unordered_map<int, int> predecessor;

    
    void DFS_recur (int vertex, unordered_map<int, int> *visited, list<int> * topo_list) {
        // Mark visited
        visited->insert(make_pair(vertex, 1));
        // Show its visits
        for (auto it = EL[vertex].begin(); it != EL[vertex].end(); it++) {
            // Traverse thru the columns on the same row
            if (visited->find(it->second) == visited->end()) {
                // unvisited vertex
                DFS_recur(it->second, visited, topo_list);
            }
            // Else skip it
        }
        // Finish DFS, add to back of list
        topo_list->push_back(vertex);
    }

    
    void relax (int v, int v2, int w) {
        if (added_weight[v2] > added_weight[v] + w) {
            added_weight[v2] = added_weight[v] + w;
            predecessor[v2] = v;
        }
    }


public:
    
    DP (int size) {
        this->numv = size;
    }
    
    
    void connect (int v, int v2, int weight) {
        EL[v].push_back(make_pair(weight, v2));
        added_weight[v] = INT_MAX;
        added_weight[v2] = INT_MAX;
        
    }
    
    void topo_sort_dfs (int v) {
        list<int> topo;
        unordered_map<int, int> visited;
        DFS_recur(v, &visited, &topo);
        topo.reverse();
        
        
        added_weight[v] = 0;
        while (!topo.empty()) {
            // Relax all outgoing edges for curr
            int curr = *topo.begin();
            topo.erase(topo.begin());
            for (auto it = EL[curr].begin(); it != EL[curr].end(); it++) {
                relax(curr, it->second, it->first);
            }
        }
    }
    
    
    void get_weight (int v) {
        cout << added_weight[v] << endl;
    }
    
    int get_distance (int source, int destination) {
        topo_sort_dfs(source);
        return added_weight[destination];
    }

};


