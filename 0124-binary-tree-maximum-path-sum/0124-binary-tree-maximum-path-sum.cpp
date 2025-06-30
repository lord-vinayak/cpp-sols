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
int maxpath(TreeNode* root, int &sum){
    if(!root) return 0;
    int left = maxpath(root->left, sum);
    int right = maxpath(root->right, sum);
   
    sum = max(root->val, sum);
    sum = max(root->val + left, sum);
    sum = max(root->val + right, sum);
    sum = max(((root->val)+left+right), sum);
    return max(root->val, root->val+max(left, right));
    
}
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int sum = INT_MIN;
        maxpath(root, sum);
        return sum;
    }
};