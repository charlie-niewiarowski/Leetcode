class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;

        for (char c : num) {
            while (!res.empty() && k > 0 && res.back() > c) {
                res.pop_back();
                --k;
            }

            res.push_back(c);
        }

        while (k > 0) {
            res.pop_back();
            --k;
        }

        res.erase(0, res.find_first_not_of('0'));
        return (res.empty()) ? "0" : res;
    }
};