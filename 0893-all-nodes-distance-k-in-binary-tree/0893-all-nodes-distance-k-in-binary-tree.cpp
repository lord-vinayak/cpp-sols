/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*>parent;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            if(f->left){
                parent[f->left] = f;
                q.push(f->left);
            }
            if(f->right){
                parent[f->right] = f;
                q.push(f->right);
            }
        }
        unordered_map<TreeNode*, bool> vis;
        q = {};
        q.push(target);
        vis[target] = true;
        int c=0;
        while(!q.empty()){
            int s = q.size();
            if(c++==k) break;
            for(int i=0; i<s; i++){
                TreeNode* f = q.front();
                q.pop();
                if(f->left && !vis[f->left]){
                    q.push(f->left);
                    vis[f->left] = true;
                }
                if(f->right && !vis[f->right]){
                    q.push(f->right);
                    vis[f->right] = true;
                }
                if(parent[f] && !vis[parent[f]]){
                    q.push(parent[f]);
                    vis[parent[f]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* f = q.front();
            q.pop();
            res.push_back(f->val);
        }
        return res;
    }
};