class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [] (const string a, const string b) {
            return a.size() < b.size();
        });

        int n = words.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isPredecessor(words[i], words[j])) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        int res = 1;
        for (const int& val : dp) {
            if (val > res) res = val;
        }

        return res;
    }

private:
    bool isPredecessor(const string& a, const string& b) {
        if (a.size() != b.size() + 1) return false;

        bool skipped = false;
        int l = 0; int r = 0;

        while (r < b.size()) {
            if (a[l] != b[r]) {
                if (skipped) return false;
                skipped = true;
            } else ++r;

            ++l;
        }

        return true;
    }
};