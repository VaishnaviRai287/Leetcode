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
    TreeNode* deleteNode(TreeNode* root, int key) {
        //locate
        if(!root) return NULL;
        if(root->val == key){
            return helper(root);
        }
        TreeNode* cur = root;
        while(cur){
            if(key < cur->val){
                if(cur->left && cur->left->val == key){
                    cur->left = helper(cur->left);
                    break;
                }else{
                    cur = cur->left;
                }

            }else{
                if(cur->right && cur->right->val == key){
                    cur->right = helper(cur->right);
                    break;
                }else{
                    cur = cur->right;
                }
            }
        }
        return root;
    }

    TreeNode* helper(TreeNode* node){
        if(node->left == NULL){
            return node->right;
        }
        else if(node->right == NULL){
            return node->left;
        }
        TreeNode* rightsub = node->right;
        TreeNode* lastright = findlastright(node->left);
        lastright->right = rightsub;
        return node->left;
    }
    TreeNode* findlastright(TreeNode* node){
        while(node->right != NULL){
            node = node->right;
        }
        return node;
    }
};