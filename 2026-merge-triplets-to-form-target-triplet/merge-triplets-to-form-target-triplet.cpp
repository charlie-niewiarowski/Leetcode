class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int> res;

        for (const auto& tri : triplets) {
            if (tri[0] > target[0] or tri[1] > target[1] or tri[2] > target[2]) continue;

            for (int i = 0; i < 3; ++i) {
                if (tri[i] == target[i]) res.insert(tri[i]);
            }
        }

        set<int> sol;
        for (const int& val : target) sol.insert(val);
        return res == sol;
    }
};