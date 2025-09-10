class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Compute the degree of each node
        vector<long long> degrees(n, 0);
        for (unsigned int i = 0; i < roads.size(); ++i) {
            degrees[roads[i][0]] += 1;
            degrees[roads[i][1]] += 1;
        }

        std::sort(degrees.begin(), degrees.end());

        // Iterate through the arr summing up the importance as we go (importance * degree)
        long long res = 0;
        for (long long i = n; i >= 1; --i) {
            res += degrees[i - 1] * i;
        }

        return res;
    }
};