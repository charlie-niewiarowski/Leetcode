class Solution {
private:
    bool canEat(vector<int>& piles, int h, int k) {
        long long hrs = 0;
        for (const auto p : piles) {
            hrs += p / k;
            if (p % k) ++hrs;
        }
        return hrs <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());

        int res = r;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (canEat(piles, h, m)) {
                res = m;
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }

        return res;
    }
};