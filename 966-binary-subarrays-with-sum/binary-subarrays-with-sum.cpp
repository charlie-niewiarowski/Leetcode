class Solution {
public:
    int countAtMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0, sum = 0, res = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (l <= r && sum > k) {
                sum -= nums[l++];
            }
            res += r - l + 1;
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};