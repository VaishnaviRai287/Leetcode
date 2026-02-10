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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->val == start) startNode = cur;

            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> bfs;
        bfs.push(startNode);
        visited.insert(startNode);

        int time = -1;

        while (!bfs.empty()) {
            int size = bfs.size();
            time++;

            while (size--) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    bfs.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    bfs.push(node->right);
                }

                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    bfs.push(parent[node]);
                }
            }
        }

        return time;
    }
};