/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                level++;
                if (!q.empty())
                    q.push(NULL);
            } else {
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return level;
    }
};