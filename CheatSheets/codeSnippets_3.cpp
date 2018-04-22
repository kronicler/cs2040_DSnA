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



