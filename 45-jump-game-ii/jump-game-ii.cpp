class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l{}, r{}, res{};

        while (r < nums.size() - 1) {
            int farthest{};
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