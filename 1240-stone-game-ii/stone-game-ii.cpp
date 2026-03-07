/*
dp[starting index][current M]
dp[i][m] = max(dp[i + 1][M = max(currM, X)])
dp[n - 1][all possible M's = piles[n - 1];
*/

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<int> suffixes(n, 0);
        suffixes[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixes[i] = suffixes[i + 1] + piles[i];
        }
        
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int m = 1; m <= n; ++m) {
                if (i + (2 * m) >= n) {
                    dp[i][m] = suffixes[i];
                }
                else {
                    for (int x = 1; x <= 2 * m; ++x) {
                        dp[i][m] = max(dp[i][m], suffixes[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }

        return dp[0][1];
    }
};