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
bool symmetric(TreeNode* x, TreeNode* y){
    if(x==nullptr && y==nullptr) return true;
    else if(x==nullptr || y==nullptr) return false;
    else if(x->val!=y->val) 
            return false;
    return (x!=nullptr && y!=nullptr) && symmetric(x->left, y->right) && symmetric(x->right, y->left);
}
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return false;
        return symmetric(root->left, root->right);
    }
};