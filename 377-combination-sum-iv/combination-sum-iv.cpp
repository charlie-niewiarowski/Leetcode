class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0) return 1;

        vector<unsigned int> dp(target + 1, 0);
        for (int goal = 1; goal <= target; ++goal) {
            for (const int& num : nums) {
                if (goal - num > 0) {
                    dp[goal] += dp[goal - num];
                } else if (goal - num == 0) {
                    dp[goal] += 1;
                }
            }
        }

        return int(dp[target]);
    }
};