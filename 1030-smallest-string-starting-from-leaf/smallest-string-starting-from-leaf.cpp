/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string res = "";
        deque<pair<TreeNode*, string>> q;
        q.emplace_back(root, string(1, root->val + 'a'));

        while (!q.empty()) {
            auto [node, curr] = q.front(); q.pop_front();

            if (!node->left && !node->right) {
                if (res.empty() || curr < res) res = curr;
            }

            if (node->left) q.emplace_back(node->left, static_cast<char>(node->left->val + 'a') + curr);
            if (node->right) q.emplace_back(node->right, static_cast<char>(node->right->val + 'a') + curr);
        }

        return res;
    }
};