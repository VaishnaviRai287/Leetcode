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
    int cnt = 0;
    int val = 0;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return val;
    }
    void inorder(TreeNode* root, int k){
        if(!root || cnt>=k) return;
        inorder(root->left, k);
        if(++cnt == k) val = root->val;
        inorder(root->right, k);
    }
};