/*
    get answer hashmap from t

    for character in s
        if answer.contains(current character) 
            map[c] += 1
            if map[c] == answer[c]
                statisfied += 1
        

        while (satisfied == len(t))
            res = max(res, r - l + 1)
            shrink
            recompute satisfied

    return res
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        unordered_map<char, int> tCounts;
        for (const auto c : t) {
            tCounts[c] += 1;
        }

        unordered_map<char, int> winCounts;
        int l = 0, satisfied = 0, minDist = INT_MAX;
        pair<int, int> res;

        for (int r = 0; r < n; ++r) {
            char c = s[r];
            winCounts[c] += 1;

            if (tCounts.contains(c) && winCounts[c] == tCounts[c]) ++satisfied;

            while (l <= r && satisfied == tCounts.size()) {
                if (r - l + 1 < minDist) {
                    minDist = r - l + 1;
                    res = {l, r};
                }

                c = s[l++];
                winCounts[c] -= 1;
                if (tCounts.contains(c) && winCounts[c] < tCounts[c]) --satisfied;
            }
        }

        return (minDist != INT_MAX) ? s.substr(res.first, minDist) : "";
    }
};