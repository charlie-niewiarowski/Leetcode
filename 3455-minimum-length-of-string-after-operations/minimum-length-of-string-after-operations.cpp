class Solution {
public:
    int minimumLength(string s) {
        vector<int> counts(26, 0);
        int res = s.size();

        for (char c : s) {
            int idx = c - 'a';
            if (counts[idx] == 2) {
                counts[idx] -= 1;
                res -= 2;
            } else {
                counts[idx] += 1;
            }
        }
        return res;
    }
};