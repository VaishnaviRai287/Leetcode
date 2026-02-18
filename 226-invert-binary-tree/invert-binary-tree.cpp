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
    void swapChildren(TreeNode* t) {
        if (t == nullptr) { 
            return;
        }
        swap(t->left, t->right); 
        swapChildren(t->left);
        swapChildren(t->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        swapChildren(root);
        return root;
    }
};