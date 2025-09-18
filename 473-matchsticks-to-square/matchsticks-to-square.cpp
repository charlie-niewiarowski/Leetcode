class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (perimeter % 4) return false;

        int length = perimeter / 4;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());

        return backtrack(matchsticks, sides, 0, length);
    }
private:
    bool backtrack(vector<int>& matchsticks, vector<int>& sides, int idx, int length) {
        if (idx == matchsticks.size()) return true;

        for (int i = 0; i < 4; ++i) {
            if (matchsticks[idx] + sides[i] <= length) {
                sides[i] += matchsticks[idx];
                if (backtrack(matchsticks, sides, idx + 1, length)) return true;
                sides[i] -= matchsticks[idx];
            }

            if (sides[i] == 0) break;
        }

        return false;
    }
};