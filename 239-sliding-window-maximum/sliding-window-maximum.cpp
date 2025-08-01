class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<int> q;
        int l = 0; int r = 0;

        while (r < static_cast<int>(nums.size())) {
            while (!q.empty() && nums[q.back()] < nums[r]) q.pop_back();
            q.push_back(r);

            if (l > q.front()) q.pop_front();

            if (r + 1 >= k) {
                output.push_back(nums[q.front()]);
                l += 1;
            }

            r += 1;
        }

        return output;
    }
};