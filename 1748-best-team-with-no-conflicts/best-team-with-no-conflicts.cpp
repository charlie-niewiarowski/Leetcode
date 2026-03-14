class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        vector<pair<int, int>> players;
        for (int i = 0; i < n; ++i) players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());

        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = players[i].second;
            for (int j = 0; j < i; ++j) {
                if (players[i].second >= players[j].second) {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};