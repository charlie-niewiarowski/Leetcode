class Solution {
    vector<int> nums;
    vector<vector<int>> res;
private:
    void backtrack(vector<int>& curr, unordered_map<int, int>& counter) {
        int n = nums.size(), m = curr.size();
        if (m >= n) {
            res.push_back(curr);
            return;
        }

        for (auto& [num, cnt] : counter) {
            if (cnt == 0) continue;

            counter[num] -= 1;
            curr.push_back(num);
            backtrack(curr, counter);
            curr.pop_back();
            counter[num] += 1;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        unordered_map<int, int> counter;
        for (auto& num : nums) counter[num] += 1;
        vector<int> curr;

        backtrack(curr, counter);
        return res;
    }
};