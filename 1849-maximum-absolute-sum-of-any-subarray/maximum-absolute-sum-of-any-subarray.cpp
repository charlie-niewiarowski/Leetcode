class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), currMax = 0, currMin = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            currMax = max(0, currMax + nums[i]);
            currMin = min(0, currMin + nums[i]);
            res = max(res, max(currMax, abs(currMin)));
        }      

        return res;
    }
};