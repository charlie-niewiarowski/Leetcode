class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l{}, r{};
        int res{};

        while (r < n - 1) {
            int farthest = 0;
            for (int i{l}; i < r + 1; ++i) {
                farthest = max(farthest, i + nums[i]);
            }

            l = r + 1;
            r = farthest;
            ++res;
        }

        return res;
    }
};