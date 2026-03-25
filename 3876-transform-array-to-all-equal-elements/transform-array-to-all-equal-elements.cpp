class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>& positive = nums;
        vector<int> negative = nums;

        int num_positive = 0, num_negative = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (positive[i] == -1) {
                positive[i + 1] *= -1;
                ++num_positive;
            }
            if (negative[i] == 1) {
                negative[i + 1] *= -1;
                ++num_negative;
            }
        }

        int min_ops = INT_MAX;
        if (positive[n - 1] == 1) {
            min_ops = num_positive;
        }
        if (negative[n - 1] == -1) {
            min_ops = min(min_ops, num_negative);
        }

        return min_ops <= k;
    }
};