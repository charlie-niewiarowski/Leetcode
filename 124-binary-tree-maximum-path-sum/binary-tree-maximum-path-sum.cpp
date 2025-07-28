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
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        int throwaway = dfs(root, res);
        return res;
    }

    int dfs(TreeNode* subroot, int& best) {
        if (!subroot) return 0;

        int left = std::max(dfs(subroot->left, best), 0);
        int right = std::max(dfs(subroot->right, best), 0);

        best = std::max(best, subroot->val + left + right);
        return subroot->val + max(left, right);
    }
};