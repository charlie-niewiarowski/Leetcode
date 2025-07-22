class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int start = 0;
        int currTotal = 0; int total = 0;
        for (unsigned int i = 0; i < gas.size(); ++i) {
            currTotal += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (currTotal < 0) {
                currTotal = 0;
                start = i + 1;
            }
        }

        return -1 * (total < 0) + start * (total >= 0);
    }
};