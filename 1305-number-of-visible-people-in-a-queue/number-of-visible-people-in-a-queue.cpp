

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> res(n, 0);

        for (int i = n - 1; i >=0; --i) {
            while (!stk.empty() && heights[stk.top()] < heights[i]) {
                stk.pop();
                ++res[i];
            }

            if (!stk.empty()) ++res[i];
            stk.push(i);
        }

        return res;
    }
};