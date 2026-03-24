class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> adj;
        for (const auto& t : tickets) {
            const string& from = t[0], to = t[1];
            adj[from][to] += 1;
        }

        vector<string> res;
        stack<string> stk;
        stk.push("JFK");

        while (!stk.empty()) {
            string curr = stk.top();

            if (adj[curr].empty()) {
                res.push_back(curr);
                stk.pop();
            }
            else {
                auto itr = adj[curr].begin();
                string next = itr->first;

                if (itr->second == 1) adj[curr].erase(itr);
                else itr->second -= 1;

                stk.push(next);
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};