class Solution {
public:
    int minimumLength(string s) {
        int res = s.size();
        unordered_map<char, int> counts;

        for (const char& c : s) {
            if (counts[c] == 2) {
                counts[c] -= 1;
                res -= 2;
            } else {
                counts[c] += 1;
            }
        }

        return res;
    }
};