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



