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
    
    void dfs(TreeNode* node, string a, vector<string>& res) {
        if (!node->left && !node->right) {
            res.push_back(a);
            return;
        }

        vector<TreeNode*> children = {node->left, node->right};
        for (auto child : children) {
            if (child) {
                dfs(child, a + "->" + to_string(child->val), res);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> res;
        dfs(root, to_string(root->val), res);
        return res;
    }
};