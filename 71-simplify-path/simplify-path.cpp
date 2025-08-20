class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;
        stringstream ss(path); 

        while (getline(ss, curr, '/')) {
            if (curr == "..") {
                if (!stack.empty()) stack.pop_back(); 
            } else if (curr != "." && curr != "") {
                stack.push_back(curr);
            }
        }

        string res = "/";
        for (unsigned int i = 0; i < stack.size(); ++i) {
            if (i > 0) res += "/";
            res += stack[i];
        }

        return res;
    }
};