class Solution {
private:
    int helper(vector<int>& nums, int k) {
        int l = 0, res = 0;

        unordered_map<int, int> count;
        for (int r = 0; r < nums.size(); ++r) {
            count[nums[r]] += 1;

            while (count.size() > k) {
                count[nums[l]] -= 1;
                if (count[nums[l]] == 0) {
                    count.erase(nums[l]);
                }
                ++l;
            }

            res += r - l + 1;
        }

        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};