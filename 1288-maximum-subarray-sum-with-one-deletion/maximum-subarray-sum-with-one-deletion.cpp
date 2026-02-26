class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int none = arr[0], one = arr[0], res = arr[0];

        for (int i = 1; i < n; ++i) {
            one = max(none, one + arr[i]);
            none = max(none + arr[i], arr[i]);
            res = max(res, max(none, one));
        }

        return res;
    }
};