class Solution {
private:
    static size_t hash_combine(size_t seed, size_t v) {
        return seed ^ (v + 0x9e3779b9 + (seed << 6) + (seed >> 2));
    }

    struct VectorHash {
        std::size_t operator()(const std::vector<int>& v) const {
            std::size_t seed = v.size();
            for (int i : v) {
                seed = hash_combine(seed, std::hash<int>{}(i));
            }
            return seed;
        }
    };

    unordered_map<vector<int>, int, VectorHash> cache;

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        if (cache.contains(needs)) return cache[needs];
        int n = needs.size();

        int min_cost = 0;
        for (int i = 0; i < n; ++i) {
            min_cost += needs[i] * price[i];
        }
        if (min_cost == 0) return 0;

        for (const auto& offer : special) {
            vector<int> new_needs(n, 0);
            bool overflows = false;

            for (int i = 0; i < n; ++i) {
                int remainder = needs[i] - offer[i];
                if (remainder < 0) {
                    overflows = true;
                    break;
                }
                new_needs[i] = remainder;
            }

            if (overflows) continue;
            min_cost = min(min_cost, offer[n] + dfs(price, special, new_needs));
        }

        cache[needs] = min_cost;
        return min_cost;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};