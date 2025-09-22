class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>{0, 0});
        int lenLis = 0, res = 0;

        for (int i = n - 1; i >= 0; --i) {
            int maxLen = 1, maxCount = 1;

            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    int length = dp[j][0], count = dp[j][1];

                    if (length + 1 > maxLen) {
                        maxLen = length + 1;
                        maxCount = count;
                    } else if (length + 1 == maxLen) {
                        maxCount += count;
                    }
                }
            }

            if (maxLen > lenLis) {
                lenLis = maxLen;
                res = maxCount;
            } else if (maxLen == lenLis) {
                res += maxCount;
            }

            dp[i] = {maxLen, maxCount};
        }

        return res;
    }
};