/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        deque<Node*> q;
        q.push_back(root);

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;

            for (int i = 0; i < sz; ++i) {
                Node* curr = q.front(); q.pop_front();
                level.push_back(curr->val);

                for (const auto child : curr->children) {
                    q.push_back(child);
                }
            }

            res.push_back(level);
        }

        return res;
    }
};