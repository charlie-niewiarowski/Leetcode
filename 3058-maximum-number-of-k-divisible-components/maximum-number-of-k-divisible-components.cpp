class Solution {
private:
    int n;

    void build_tree(vector<vector<int>>& tree, vector<vector<int>>& adj, int node, int parent) {
        for (int nei : adj[node]) {
            if (nei == parent) continue;

            tree[node].push_back(nei);
            build_tree(tree, adj, nei, node);
        }
    }

    long long compute_sums(vector<vector<int>>& tree, vector<int>& values, vector<long long>& sums, int root) {
        long long res = values[root];

        for (auto& child : tree[root]) {
            res += compute_sums(tree, values, sums, child);
        }

        sums[root] = res;
        return res;
    }

    long long split_dfs(vector<vector<int>>& tree, vector<long long>& sums, int root, int k) {
        int res = 0;
        for (auto& child : tree[root]) {
            if (sums[child] % k == 0) ++res;
            res += split_dfs(tree, sums, child, k);
        }

        return res;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->n = n;
        int root = 0;

        // build adj list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // build tree
        vector<vector<int>> tree(n);
        build_tree(tree, adj, root, -1);
        
        // compute sums
        vector<long long> sums(n);
        long long throwaway = compute_sums(tree, values, sums, root);

        // recurse and split
        return split_dfs(tree, sums, root, k) + 1;
    }
};