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
int balanced(TreeNode* root, bool &bal){
    if(!root || !bal) return 0;
    int lh = balanced(root->left, bal);
    int rh = balanced(root->right, bal);
    if(abs(lh-rh)>1) bal = false;
    return max(lh, rh)+1;

}
    bool isBalanced(TreeNode* root) {
        bool bal = true;
        balanced(root, bal);
        return bal;
    }
};