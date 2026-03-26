class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);

        int l = 0, r = n;
        while (l <= r) {
            int m1 = (l + r) / 2;
            int m2 = (n + m + 1) / 2 - m1;

            int minOne = (m1 == n) ? INT_MAX : nums1[m1];
            int maxOne = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int minTwo = (m2 == m) ? INT_MAX : nums2[m2];
            int maxTwo = (m2 == 0) ? INT_MIN : nums2[m2 - 1];

            if (minOne >= maxTwo && minTwo >= maxOne) {
                if ((n + m) % 2 == 0) {
                    return (min(minOne, minTwo) + max(maxOne, maxTwo)) / 2.0;
                }
                else {
                    return max(maxOne, maxTwo);
                }
            }
            else if (minOne < maxTwo) {
                l = m1 + 1;
            }
            else {
                r = m1 - 1;
            }
        }

        return 0.0;
    }
};