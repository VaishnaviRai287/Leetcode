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
    int maxDistance = 0;

    int dfs(TreeNode* root, int start) {
        if (!root) return 0;

        int left = dfs(root->left, start);
        int right = dfs(root->right, start);
        if (root->val == start) {
            maxDistance = max(maxDistance, max(left, right));
            return -1;
        }
        if (left < 0) {
            int dist = abs(left);
            maxDistance = max(maxDistance, dist + right);
            return left - 1;
        }
        if (right < 0) {
            int dist = abs(right);
            maxDistance = max(maxDistance, dist + left);
            return right - 1;
        }
        return max(left, right) + 1;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return maxDistance;
    }
};