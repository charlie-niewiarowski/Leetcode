class Solution {
public:
    int minOperations(string s) {
        char min_char{'z'}, all_a{1};

        for (size_t i{}; i < s.size(); ++i) {
            if (s[i] != 'a') {
                min_char = std::min(min_char, s[i]);
                all_a = 0;
            }
        }

        return (all_a) ? 0 : 26 - (min_char - 'a');
    }
};