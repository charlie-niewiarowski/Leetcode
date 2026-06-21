class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        int sum{numbers[l] + numbers[r]};
        while (sum != target) {
            if (sum > target) {
                sum -= numbers[r--];
                sum += numbers[r];
            }
            else {
                sum -= numbers[l++];
                sum += numbers[l];
            }
        }

        return {l + 1, r + 1};
    }
};