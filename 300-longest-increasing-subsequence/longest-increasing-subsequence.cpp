class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i{n - 1}; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int res = dp[0];
        for (int i{1}; i < n; ++i) res = max(res, dp[i]);
        return res;
    }
};