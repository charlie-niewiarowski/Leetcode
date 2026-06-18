class Solution {
public:
    int minimumPushes(string word) {
        vector<int> occurrences(26, 0);
        for (const char ch : word) {
            ++occurrences[ch - 'a'];
        }

        std::sort(occurrences.begin(), occurrences.end(), [](int a, int b) {
            return a > b;
        });

        int res{};
        for (int i{}; i < 26 && occurrences[i] != 0; ++i) {
            if (i < 8)       res += 1 * occurrences[i];
            else if (i < 16) res += 2 * occurrences[i];
            else if (i < 24) res += 3 * occurrences[i];
            else             res += 4 * occurrences[i];
        }

        return res;
    }
};