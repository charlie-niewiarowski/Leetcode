/*
    DP table dp[i][l] = max score at that state | working backwards on i, l specifes window
    dp[i][l] depends on nums[l] * multiplier + dp[i + 1][l + 1] and nums[r] * multiplier + dp[i + 1][l]
    Base case: 
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int i = m - 1; i >= 0; --i) {
            for (int l = 0; l <= i; ++l) {
                int r = n - 1 - i + l;
                dp[i][l] = max(nums[l] * multipliers[i] + dp[i + 1][l + 1], nums[r] * multipliers[i] + dp[i + 1][l]);
            }
        }

        return dp[0][0];
    }
};