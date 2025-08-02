class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = static_cast<int>(points.size()); 
        int node = 0;
        vector<int> dist(n, INT_MAX);
        vector<bool> visit(n, false);
        int edges = 0;
        int res = 0;
        
        while (edges < n - 1)
        {
            visit[node] = true;
            int nextNode = -1;

            for (int i = 0; i < n; ++i) {
                if (visit[i]) continue;

                int currDist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                dist[i] = min(dist[i], currDist);
                if (nextNode == -1 || dist[i] < dist[nextNode]) nextNode = i;
            }

            res += dist[nextNode];
            edges += 1;
            node = nextNode;
        }

        return res;
    }
};