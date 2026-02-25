class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int max_diff = *max_element(nums.begin(), nums.end()) + *min_element(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>(2 * (max_diff + 1), 0));

        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                int idx = diff + max_diff;

                if (dp[j][idx] == 0) dp[i][idx] = 2;
                else dp[i][idx] = dp[j][idx] + 1;
                res = max(res, dp[i][idx]);
            }
        }

        return res;
    }
};