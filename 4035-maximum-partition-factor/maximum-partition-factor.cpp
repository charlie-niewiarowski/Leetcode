class Solution {
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 2) return 0;

        vector<vector<int>> dists(n, vector<int>(n, 0));
        int r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dists[i][j] = dists[j][i] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                r = max(r, dists[i][j]);
            }
        }

        int l = 0, res = 0;
        while (l <= r) {
            int m = (l + r) / 2;

            if (canPartition(dists, n, m)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }

private:
    bool canPartition(vector<vector<int>>& dists, int n, int threshold) {
        vector<int> colors(n, -1);

        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {
                if (!dfs(colors, dists, i, 0, n, threshold)) return false;
            }
        }

        return true;
    }

    bool dfs(vector<int>& colors, vector<vector<int>>& dists, int i, int color, int n, int threshold) {
        colors[i] = color;

        for (int j = 0; j < n; ++j) {
            if (i == j) continue;

            if (dists[i][j] < threshold) {
                if (colors[j] == -1) {
                    if (!dfs(colors, dists, j, 1 - color, n, threshold)) return false;
                } else if (colors[j] == color) return false;
            }
        }

        return true;
    }
};