/*
get all of the leaves to start
then run bfs where elems are cars represented as {city, seats available}
when we reach a new city and it hasn't already been visited
we try to add the rep to the car if the seats are available otherwise we give him a new car
*/

class Solution {
private:
    long long res = 0;
    int seats;

    int dfs(int i, int prev, vector<vector<int>>& adj, int people = 1) {
        for (int& x: adj[i]) {
            if (x == prev) continue;
            people += dfs(x, i, adj);
        }
        if (i != 0) res += (people + seats - 1) / seats;
        return people;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adj(roads.size() + 1);
        this->seats = seats;

        for (const auto& e : roads) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, 0, adj);
        return res;
    }
};