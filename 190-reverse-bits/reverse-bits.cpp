class Solution {
public:
    int reverseBits(int n) {
        unsigned int res = 0;
        for (int i = 0; i < 32; ++i) {
            unsigned int bit = (n >> i) & 1;
            res += (bit << (31 - i));
        }
        return res;
    }
};