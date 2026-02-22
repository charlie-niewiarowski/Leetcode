class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k) return false;

        int target = total / k;
        int N = 1 << n;

        vector<int> dp(N, -1);
        dp[0] = 0;

        for (int mask = 0; mask < N; mask++) {
            if (dp[mask] == -1) continue;

            for (int j = 0; j < n; j++) {
                if (!(mask & (1<<j))) {
                    int next = dp[mask] + nums[j];
                    if (next <= target) {
                        int newMask = mask | (1<<j);
                        dp[newMask] = next % target;
                    }
                }
            }
        }

        return dp[N-1] == 0;
    }
};