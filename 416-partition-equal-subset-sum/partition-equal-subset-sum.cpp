class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) return false;

        int n = nums.size(), half = total / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));
        
        for (int i = 0; i <= n; ++i) dp[i][0] = true; 

        for (int i = n - 1; i >= 0; --i) {
            for (int amount = 0; amount <= half; ++amount) {
                int num = nums[i];
                if (amount - num >= 0) dp[i][amount] = dp[i + 1][amount] || dp[i + 1][amount - num];
                else dp[i][amount] = dp[i + 1][amount];
            }
        }

        return dp[0][half];
    }
};
