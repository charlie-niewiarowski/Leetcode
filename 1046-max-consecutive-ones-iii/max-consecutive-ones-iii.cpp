class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, res = 0;

        for (int r = 0; r < n; ++r) {
            k -= nums[r] == 0;

            while (k < 0) {
                k += nums[l] == 0;
                ++l;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};