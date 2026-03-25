class Solution {
private:
    vector<string> normals = {"One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    vector<string> tens = {"Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    vector<string> teens = {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string> suffixes = {"", "Thousand ", "Million ", "Billion "};

    string helper(const string&& s) {
        int n = s.size();
        string res = "";

        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            int digit = static_cast<int>(c - '0');
            int pos = n - 1 - i;

            if (digit == 0) continue;

            if (pos == 0) {
                res = normals[digit - 1] + res;
            }
            else if (pos == 1) {
                if (digit == 1) {
                    int next_digit = static_cast<int>(s[i + 1] - '0');
                    res = teens[next_digit];
                }
                else {
                    res = tens[digit - 2] + res;
                }
            }
            else if (pos == 2) {
                res = normals[digit - 1] + "Hundred " + res;
            }
        }

        return res;
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string s = to_string(num);
        int n = s.size();

        int groups = (n + 2) / 3;
        int suffixCounter = groups - 1;
        string res = "";

        int firstGroupSize = n % 3;
        if (firstGroupSize == 0) firstGroupSize = 3;

        int l = 0;
        int r = firstGroupSize;

        while (l < n) {
            string chunk = s.substr(l, r - l);
            string interpretation = helper(std::move(chunk));

            if (!interpretation.empty()) {
                res += interpretation + suffixes[suffixCounter];
            }
            --suffixCounter;

            l = r;
            r = min(r + 3, n);
        }

        while (!res.empty() && res.back() == ' ') res.pop_back();

        return res;
    }
};