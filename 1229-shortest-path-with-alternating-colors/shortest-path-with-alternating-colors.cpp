class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : redEdges)
            adj[e[0]].push_back({e[1], 0});

        for (auto& e : blueEdges)
            adj[e[0]].push_back({e[1], 1});


        vector<vector<bool>> visited(n, vector<bool>(2, false));
        vector<int> dist(n, -1);

        queue<tuple<int,int,int>> q;
        q.push({0, 0, 0});
        q.push({0, 1, 0});
        visited[0][0] = visited[0][1] = true;
        dist[0] = 0;

        while (!q.empty()) {
            auto [node, color, d] = q.front(); q.pop();

            for (auto& [next, next_color] : adj[node]) {
                if (next_color != color && !visited[next][next_color]) {
                    visited[next][next_color] = true;
                    q.push({next, next_color, d + 1});

                    if (dist[next] == -1)
                        dist[next] = d + 1;
                }
            }
        }

        return dist;
    }
};