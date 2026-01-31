class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, std::numeric_limits<int>::max() - 1);
        dp[n - 1] = 0;

        for (int i{n - 2}; i >= 0; --i) {
            int max_steps{nums[i]};
            for (int j{1}; j <= max_steps && i + j < n; ++j) {
                dp[i] = min(dp[i], dp[i + j] + 1);
            }
        }

        return dp[0];
    }
};