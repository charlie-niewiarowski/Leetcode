class DSU {
    vector<int> pars;
public:
    DSU(int n) {
        pars = vector(n, -1);
    }

    int find(int val) {
        if (pars[val] < 0) return val;
        return pars[val] = find(pars[val]);
    }

    bool unionSets(int one, int two) {
        int p1 = find(one); int p2 = find(two);

        if (p1 == p2) return false;

        if (pars[p1] < pars[p2]) {
            pars[p1] += pars[p2];
            pars[p2] = p1;
        } else {
            pars[p2] += pars[p1];
            pars[p1] = p2;
        }
        
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToAcc; // email -> index of acc

        // Build union-find structure
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (emailToAcc.count(email)) {
                    dsu.unionSets(i, emailToAcc[email]);
                } else {
                    emailToAcc[email] = i;
                }
            }
        }

        // Group emails by leader account
        map<int, vector<string>> emailGroup; // index of acc -> list of emails
        for (const auto& [email, accId] : emailToAcc) {
            int leader = dsu.find(accId);
            emailGroup[leader].push_back(email);
        }

        // Build result
        vector<vector<string>> res;
        for (auto& [accId, emails] : emailGroup) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }

        return res;
    }
};