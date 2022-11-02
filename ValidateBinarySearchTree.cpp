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
    bool isValidBST(TreeNode* root) {
        int min, max;
        return isValidBSThelper(root, min, max);
    }
    bool isValidBSThelper(TreeNode* Node, int &min, int &max) {
        if (!Node->left && !Node->right) {
            min = max = Node->val;
            return true;
        }
        int min_left=Node->val, max_left=Node->val, min_right=Node->val, max_right=Node->val;
        bool q_left=true, q_right=true;
        if (Node->left) {
            if(Node->left->val >= Node->val) {
                return false;
            }
            q_left = (isValidBSThelper(Node->left, min_left, max_left));
            if (Node->val<=max_left) return false;
        }
        if (Node->right) {
            if(Node->right->val <= Node->val) {
                return false;
            }
            q_right = (isValidBSThelper(Node->right, min_right, max_right));
            if (Node->val>=min_right) return false;
        }
        min = min_left;
        max = max_right;
        return (q_left && q_right);
    }
};
