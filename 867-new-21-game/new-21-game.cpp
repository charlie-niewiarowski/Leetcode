class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1.0;

        vector<double> dp(n + 1);
        dp[0] = 1;

        double sum = 1;
        for (int r = 1; r <= n; ++r) {
            dp[r] = sum / maxPts;

            if (r < k) sum += dp[r];
            if (r - maxPts >= 0 && r - maxPts < k) sum -= dp[r - maxPts];
        }

        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};