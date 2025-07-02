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
TreeNode* res;
TreeNode* findmin(TreeNode* root){
    while(root->left) root=root->left;
    return root;
}
TreeNode* del(TreeNode* root, int key){
    if(!root) return nullptr;
        if(key<root->val) root->left = del(root->left, key);
        else if(key>root->val) root->right = del(root->right, key);
        else{
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            else if(root->left && root->right){
                TreeNode* temp = root->right;
                while(temp->left) temp=temp->left;
                root->val = temp->val;
                root->right = del(root->right, temp->val);
            }
            else{
                TreeNode* child = (root->left)?root->left:root->right;
                delete root;
                return child;
            }
        }
        return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        res = del(root, key);
        return res;
    }
};