class adj_mtx {
    // Big space complexity of O(V^2)
    
private:
    bool arr[10][10]; // Simple unwieghted adjacency mtx
    // Num rows is also num of vertices
    int numEdges, numV;
public:
    adj_mtx (int numV) {this->numV = numV;}
    
    void connect (int v, int v2) {
        arr[v][v2] = true;
        arr[v2][v] = true;
        numEdges++;
    }
    void disconnect (int v, int v2) {
        arr[v][v2] = false;
        arr[v2][v] = false;
        numEdges--;
    }
    
    bool isConnected (int v, int v2) {
        // O(1)
        return arr[v][v2];
        // For a directed graph, we have to consider the other way round ie arr[v2][v]
    }
    
    int getEdges () {
        return numEdges;
    }
    int getV () {
        return numV;
    }
    
    void find_neighbour (int v) {
        // Slow - O(N)
        for (int i = 0; i < 10; i++) {
            if (arr[v][i]) {
                cout << i << endl;
            }
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
    
    // TODO: Add in the basic functions for this class too
    
};

// TODO: Fill in more theory on graphs like acyclic or special graphs down here.
