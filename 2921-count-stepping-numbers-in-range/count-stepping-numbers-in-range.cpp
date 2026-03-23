/*
    dp[current_digit][digit_value][tight to high][tight to low]

    if current_digit == high[digit]: use tight to high and both tight and not tight to low
    if current_digit == low[digit]: use tight to low and both tight and not tight to high
    if current_digit is between: use all four combinations
*/

class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        int MOD = 1e9 + 7;

        // Count stepping numbers from "0" to num (inclusive)
        auto count = [&](string num) -> long long {
            int n = num.size();
            // memo[pos][last_digit][tight][started]
            vector<vector<vector<vector<int>>>> memo(
                n, vector<vector<vector<int>>>(10, vector<vector<int>>(2, vector<int>(2, -1))));

            function<long long(int, int, bool, bool)> dp = [&](int pos, int last, bool tight, bool started) -> long long {
                if (pos == n) return started ? 1 : 0;
                if (memo[pos][last][tight][started] != -1)
                    return memo[pos][last][tight][started];

                int limit = tight ? (num[pos] - '0') : 9;
                long long res = 0;

                for (int d = 0; d <= limit; ++d) {
                    if (!started && d == 0) {
                        // still leading zeros
                        res = (res + dp(pos + 1, 0, tight && (d == limit), false)) % MOD;
                    } else if (!started || abs(d - last) == 1) {
                        // valid stepping digit
                        res = (res + dp(pos + 1, d, tight && (d == limit), true)) % MOD;
                    }
                }

                return memo[pos][last][tight][started] = res;
            };

            return dp(0, 0, true, false);
        };

        // count[high] - count[low-1], handle low="1" edge case by checking low itself
        long long ans = (count(high) - count(low) + MOD) % MOD;

        // check if low itself is a stepping number
        bool low_valid = true;
        for (int i = 1; i < low.size(); ++i)
            if (abs((low[i] - '0') - (low[i-1] - '0')) != 1) { low_valid = false; break; }

        return (ans + low_valid) % MOD;
    }
};