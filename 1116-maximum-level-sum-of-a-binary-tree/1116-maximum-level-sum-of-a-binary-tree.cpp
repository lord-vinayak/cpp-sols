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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = 0, level = 0, sum = INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size(), levelsum = 0;
            while (count--) {
                TreeNode* f = q.front();
                q.pop();
                levelsum += f->val;
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            level++;
            if (levelsum > sum) ans = level;
            sum = max(levelsum, sum);
        }
        return ans;
    }
};