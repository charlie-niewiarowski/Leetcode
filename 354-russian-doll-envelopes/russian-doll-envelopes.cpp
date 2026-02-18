class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        std::sort(envelopes.begin(), envelopes.end(), 
                [](vector<int>& a, vector<int>& b) {
                    if (a[0] != b[0]) return a[0] < b[0];
                    return a[1] > b[1];
                });
        int n = envelopes.size();
        vector<int> lis;

        for (int i{}; i < n; ++i) {
            int curr_height = envelopes[i][1];
            auto it = lower_bound(lis.begin(), lis.end(), curr_height); // earliest index where height > curr_height
            
            if (it == lis.end()) lis.push_back(curr_height);
            else *it = curr_height;
        }

        return lis.size();
    }
};