class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }


        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                --j;
            }

            swap(nums[i], nums[j]);
        }

        int l = i + 1, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            ++l; --r;
        }
    }
};