class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = nums[0], min_sum = nums[0];

        int curr_max = 0, curr_min = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curr_max += nums[i]; curr_min += nums[i]; sum += nums[i];
            max_sum = max(max_sum, curr_max);
            min_sum = min(min_sum, curr_min);

            if (curr_max < 0) curr_max = 0;
            if (curr_min > 0) curr_min = 0;
        }

        if (min_sum == sum) return max_sum;
        return max(max_sum, sum - min_sum);
    }
};