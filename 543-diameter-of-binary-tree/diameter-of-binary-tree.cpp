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
    int maxdist(TreeNode* root, int& maxi){
        if(!root) return 0;
        int lh = maxdist(root->left, maxi);
        int rh = maxdist(root->right, maxi);
        maxi = max(maxi, lh+rh);
        return 1 + max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia =0;
        maxdist(root,dia);
        return dia;
    }
};