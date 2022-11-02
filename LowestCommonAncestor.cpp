/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        isLowComAnc(root, p, q, false);
        return N;
    }
    bool isLowComAnc(TreeNode* Node, TreeNode* p, TreeNode* q, bool flag) {
        if (!Node) {
            return flag;
        }
        if (flag) {
            if (Node==p || Node==q) return true;
            return (isLowComAnc(Node->left, p, q, true) || isLowComAnc(Node->right, p, q, true));
        }
        if (Node==p || Node==q) {
            if (isLowComAnc(Node->left, p, q, true)) {
                N = Node;
                return true;
            }
            return (isLowComAnc(Node->right, p, q, true));
        }
        auto a = isLowComAnc(Node->left, p, q, false);
        auto b = isLowComAnc(Node->right, p, q, false);
        if (a && b) N=Node;
        return (a || b);
    }
private:
    TreeNode* N;
};
