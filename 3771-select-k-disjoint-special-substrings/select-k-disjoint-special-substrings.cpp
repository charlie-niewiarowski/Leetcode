/*
    dp[i][j] = can find j disjoint special substrings using s[0...i]
    
    dp[i][j] = dp[i - 1][j]
    if () dp[i][j] |= dp[i - 1][j - 1]
*/

class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int n = s.size();

        vector<pair<int, int>> start_end(26, {-1, -1});
        for (int i = 0; i < n; ++i) {
            if (start_end[s[i] - 'a'].first == -1) start_end[s[i] - 'a'].first = i;
            start_end[s[i] - 'a'].second = i;
        }

        vector<pair<int, int>> candidates;
        for (int i = 0; i < 26; ++i) {
            if (start_end[i].first == -1) continue;
            auto [start, end] = start_end[i];

            bool invalid = false;
            for (int j = start + 1; j < end; ++j) {
                const auto [new_start, new_end] = start_end[s[j] - 'a'];

                if (new_start < start) {
                    invalid = true;
                    break;
                }
                end = max(end, new_end);
            }
            
            if (!invalid && end - start != n - 1) {
                candidates.emplace_back(end, start);
            }
        }

        sort(candidates.begin(), candidates.end());
        int res = 0, last_end = -1;
        for (const auto [end, start] : candidates) {
            if (start <= last_end) continue;
            ++res;
            last_end = end;
        }

        return res >= k;
    }
};