class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(), l = 0, last_sign = INT_MAX, res = 1;

        for (int r = 1; r < n; ++r) {  
            int diff = arr[r] - arr[r - 1];
            int new_sign = (diff != 0) ? diff / abs(diff) : 0;
            
            if (new_sign != 0 && new_sign != last_sign) {
                res = max(res, r - l + 1);
                last_sign = new_sign;
            }
            else if (new_sign == 0) {
                l = r;
                last_sign = INT_MAX;
            }
            else {
                l = r - 1;
                last_sign = new_sign;
            }
        }

        return res;
    }
};