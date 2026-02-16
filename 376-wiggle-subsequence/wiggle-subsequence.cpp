class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int last_up = 1, last_down = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                last_down = last_up + 1;
            }
            else if (nums[i] > nums[i - 1]) {
                last_up = last_down + 1;
            }
        }

        return max(last_up, last_down);
    }
};