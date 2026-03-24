class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> best(n + 1, INT_MAX);
        unordered_map<int, int> pref;
        int curr_sum = 0, res = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            pref[curr_sum] = i;
            if (i < n) curr_sum += arr[i];
            if (i > 0) best[i] = best[i - 1];

            int m = curr_sum - target;
            if (pref.contains(m)) {
                int len = i - pref[m] + 1;
                best[i] = min(best[i], len);
                if (pref[m] > 0 && best[pref[m] - 1] != INT_MAX) {
                    res = min(res, len + best[pref[m] - 1]);
                }
            }
        }

        return (res == INT_MAX) ? -1 : res;
    }
};