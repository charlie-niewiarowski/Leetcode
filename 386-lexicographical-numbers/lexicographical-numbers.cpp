class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n); 
        int curr = 1;

        for (unsigned int i = 0; i < n; ++i) {
            res[i] = curr;

            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                while (curr % 10 == 9 || curr >= n) {
                    curr = int(curr / 10);
                }
                curr += 1;
            }
        }

        return res;
    }
};