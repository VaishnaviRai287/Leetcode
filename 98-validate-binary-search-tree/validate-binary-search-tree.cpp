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
        return isValid(LONG_MIN, root, LONG_MAX);
    }
    bool isValid(long min, TreeNode* root, long max ){
        if(!root) return true;
        if(root->val >= max || root->val <= min) return false;
        return (isValid(min, root->left, root->val) && isValid(root->val, root->right, max));
    }
};