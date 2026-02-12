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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i= 0; i<inorder.size(); i++){
            mpp[inorder[i]] = i; 
        }
        TreeNode* root = construct(postorder, 0, postorder.size()-1,
            inorder, 0, inorder.size()-1, mpp);
        return root;
    }

    TreeNode* construct(vector<int>& postorder, int ps, int pe, vector<int>& inorder, int is, int ie, map<int,int>& mpp){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inroot = mpp[root->val];
        int left = inroot-is;
        root->left = construct(postorder, ps, ps+left-1, inorder, is, inroot-1, mpp);
        root->right = construct(postorder, ps+left, pe-1, inorder, inroot+1, ie, mpp);
        return root;
    }
};