class Solution {
private:
    unordered_map<long long, long long> dp;

    long long solve(long long n) {
        if (n == 1) return 0;
        if (dp.contains(n)) return dp.at(n);

        if (n % 2 == 0) {
            dp[n] = 1 + solve(n / 2);
            return dp[n];
        }
        else {
            dp[n] = 1 + min(solve(n - 1), solve(n + 1));
            return dp[n];
        }
    }
public:
    int integerReplacement(int n) {
        return solve(n);
    }   
};