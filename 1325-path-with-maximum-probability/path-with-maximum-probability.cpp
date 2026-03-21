class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m = edges.size();
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        priority_queue<pair<double, int>> pq;
        pq.emplace(1.0, start_node);
        vector<double> probs(n, 0.0);
        probs[start_node] = 1.0;

        while (!pq.empty()) {
            const auto [curr_prob, curr] = pq.top(); pq.pop();

            if (curr == end_node) return curr_prob;
            if (curr_prob < probs[curr]) continue;

            for (const auto& [next, edge_prob] : adj[curr]) {
                double next_prob = curr_prob * edge_prob;
                if (next_prob > probs[next]) {
                    probs[next] = next_prob;
                    pq.emplace(next_prob, next);
                }
            }
        }

        return 0.0;
    }
};