/*
build graph
find all nodes with in-degree 0 and all nodes with out-degree 0 (starts and ends)
then push all start nodes into pq and end nodes into a hashset
perform a bfs
    pop
    scan children
    if child time < curr time + time to take child 
        set then and requeue child
return the sum it of taking all end nodes
*/

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n, vector<int>());
        vector<int> in_degree(n, 0), out_degree(n, 0);

        for (const vector<int>& pair : relations) {
            graph[pair[0] - 1].push_back(pair[1] - 1);
            in_degree[pair[1] - 1]++;
        }

        std::deque<int> q;
        vector<int> dist(n, 0);
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push_back(i);
                dist[i] = time[i];
            }
        }

        while (!q.empty()) {
            const int node = q.front();
            q.pop_front();

            for (const auto& nei : graph[node]) {
                dist[nei] = max(dist[nei], dist[node] + time[nei]);

                if (--in_degree[nei] == 0) {
                    q.push_back(nei);
                }
            }
        }

        
        int res{};
        for (int i{}; i < n; ++i) {
            res = max(res, dist[i]);
        }
        return res;
    }
};