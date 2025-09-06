class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int l = 0, r = people.size() - 1;
        int res = 0;

        while (l <= r) {
            if (people[l] + people[r] <= limit) {
                ++res; ++l; --r;
            } else {
                ++res; --r;
            }
        }

        return res;
    }
};