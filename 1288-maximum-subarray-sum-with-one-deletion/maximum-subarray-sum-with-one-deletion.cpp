class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = arr[0];
        dp[0][1] = arr[0];

        int res = arr[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
            res = max(res, max(dp[i][0], dp[i][1]));
        }

        return res;
    }
};