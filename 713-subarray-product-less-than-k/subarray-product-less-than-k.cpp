class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, l = 0;
        long product = 1;

        for (int r = 0; r < nums.size(); ++r) {
            product *= nums[r];

            while (l <= r && product >= k) {
                product /= nums[l++];
            }

            res += r - l + 1;
        }

        return res;
    }
};