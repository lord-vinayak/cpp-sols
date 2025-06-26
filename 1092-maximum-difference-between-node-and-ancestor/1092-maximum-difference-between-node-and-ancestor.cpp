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
    void maxdiff(TreeNode* root, int curmin, int curmax, int& diff) {
        if (!root)
            return;
        diff = max(diff, abs(root->val - curmin));
        diff = max(diff, abs(root->val - curmax));
        curmin = min(curmin, root->val);
        curmax = max(curmax, root->val);
        maxdiff(root->left, curmin, curmax, diff);
        maxdiff(root->right, curmin, curmax, diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff = INT_MIN;
        maxdiff(root, root->val, root->val, diff);
        return diff;
    }
};