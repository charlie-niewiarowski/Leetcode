#include <vector>
#include <cmath>
#include <immintrin.h>

class Solution {
public:
    int numSubarrayProductLessThanK(const std::vector<int>& nums, int k) {
        if (k <= 1) return 0;
        long long res = 0;
        long long product = 1;
        int l = 0;

        for (int r = 0; r < (int)nums.size(); ++r) {
            product *= nums[r];
            while (l <= r && product >= k) {
                product /= nums[l++];
            }
            res += r - l + 1;
        }

        return (int)res;
    }
};