class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), res = abs(nums[0]);    
        vector<pair<int, int>> dp(n);
        dp[0] = {nums[0], nums[0]};

        for (int i = 1; i < n; ++i) {
            dp[i].first = min(dp[i - 1].first + nums[i], nums[i]);
            dp[i].second = max(dp[i - 1].second + nums[i], nums[i]);
            res = max(res, max(abs(dp[i].first), dp[i].second));
        }      

        return res;
    }
};