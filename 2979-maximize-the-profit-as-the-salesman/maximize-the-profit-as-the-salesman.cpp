class Solution {
private:
    int binary_search(vector<vector<int>>& offers, int target_idx) {
        int target = offers[target_idx][0];

        int l = 0, r = target_idx - 1;
        int ans = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (offers[m][1] < target) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        n = offers.size();
        sort(offers.begin(), offers.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        vector<int> dp(n, 0);
        dp[0] = offers[0][2];

        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1], offers[i][2]);

            int last_interval = binary_search(offers, i);
            if (last_interval >= 0) dp[i] = max(dp[i], dp[last_interval] + offers[i][2]);
        }

        return dp[n - 1];
    }
};