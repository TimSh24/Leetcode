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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        int sum = 0;
        return hasPathSumHelper(root, sum, targetSum);
    }
    bool hasPathSumHelper(TreeNode* node, int sum, const int& targetSum ) {
        if (!node->left && !node->right) {
            if (sum+node->val == targetSum) return true;
            else return false;
        }
        bool a, b;
        if (node->left) {
            a = hasPathSumHelper(node->left, sum+node->val,targetSum);
            if (a) return true;
        }
        if (node->right) {
            b = hasPathSumHelper(node->right, sum+node->val,targetSum);
            if (b) return true;
        }
        return false;
}
};
