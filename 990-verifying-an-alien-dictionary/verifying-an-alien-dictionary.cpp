class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> order_map;
        for (int i = 0; i < order.length(); ++i) {
            order_map[order[i]] = i;
        }

        for (unsigned int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i]; string w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());

            bool breaks = false;
            for (unsigned int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    if (order_map[w1[j]] > order_map[w2[j]]) {
                        return false;
                    }
                    breaks = true;
                    break;
                }          
            }
            
            if (!breaks && w1.size() > w2.size()) return false;     
        }

        return true;
    }
};