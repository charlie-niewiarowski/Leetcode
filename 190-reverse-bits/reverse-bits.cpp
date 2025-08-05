class Solution {
public:
    int reverseBits(int n) {
        unsigned int res = 0;
        unsigned int bit = 0;
        for (int i = 0; i < 32; ++i) {
            bit = (n >> i) & 1;
            res += (bit << (31 - i));
        }
        return res;
    }
};