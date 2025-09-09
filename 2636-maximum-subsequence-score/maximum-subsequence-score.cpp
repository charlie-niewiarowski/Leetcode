class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> pairs(nums1.size());
        for (int i = 0; i < (int)nums1.size(); ++i) {
            pairs[i] = {nums1[i], nums2[i]};
        }

        std::sort(pairs.begin(), pairs.end(),
                  [](const auto& a, const auto& b) { return a.second > b.second; });

        std::vector<int> heap;
        long long n1Sum = 0, res = 0;

        for (auto& [n1, n2] : pairs) {
            n1Sum += n1;
            heap.push_back(n1);
            std::push_heap(heap.begin(), heap.end(), std::greater<>{});

            if (heap.size() > k) {
                std::pop_heap(heap.begin(), heap.end(), std::greater<>{});
                int n1Pop = heap.back();
                heap.pop_back();
                n1Sum -= n1Pop;
            }

            if (heap.size() == k) {
                res = std::max(res, n1Sum * 1LL * n2);
            }
        }

        return res;
    }
};