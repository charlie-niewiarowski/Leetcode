class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int last_end{intervals[0][1]}, res{};
        for (int i = 1; i < intervals.size(); ++i) {
            if (last_end > intervals[i][0]) {
                ++res;
            }
            else {
                last_end = intervals[i][1];
            }
        }

        return res;
    }
};