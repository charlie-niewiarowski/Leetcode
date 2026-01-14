class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        int prefix_sum = 0;
        for (int i{1}; i < n; ++i) {
            if (i >= minJump) prefix_sum += dp[i - minJump];
            if (i > maxJump) prefix_sum -= dp[i - maxJump - 1];

            dp[i] = prefix_sum > 0 && s[i] == '0';
        }

        return dp[n - 1];
    }
};