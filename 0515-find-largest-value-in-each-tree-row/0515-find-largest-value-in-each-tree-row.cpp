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
    void preorder(TreeNode* root, int level, auto& map) {
        if (!root) {
            return;
        }
        map[level].push_back(root->val);
        preorder(root->left, level + 1, map);
        preorder(root->right, level + 1, map);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        unordered_map<int, vector<int>> map;
        preorder(root, 1, map);
        int mx = INT_MIN;
        for (int i = 1; map[i].size() > 0; i++) {
            for (auto j : map[i]) {
                mx = max(mx, j);
            }
            ans.push_back(mx);
            mx = INT_MIN;
        }
        return ans;
    }
};