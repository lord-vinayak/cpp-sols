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
 #define ull unsigned long long
class Solution {
public:

// void maxwidth(TreeNode* root, int level, auto &mp){
//     if(!root) return;
//     mp[level]++;
//     if(!root->left || !root->right) mp[level+1]++;
//     maxwidth(root->left, level+1, mp);
//     maxwidth(root->right, level+1, mp);
// }
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        // unordered_map<int, int> mp;
        // maxwidth(root, 1, mp);
        // int res = 0;
        // for(auto it: mp){
        //     res = max(res, it.second);
        // }
        // return res;
        queue<pair<TreeNode*, ull>> q;
        q.push({root, 0});
        ull mw = 0;
        while(!q.empty()){
            int sz = q.size();
            ull f = q.front().second, b = q.back().second;
            mw = max(mw, (b-f)+1);
            while(sz--){
                TreeNode* c = q.front().first;
                ull x = q.front().second -1 ;
                q.pop();
                if(c->left) q.push({c->left, 2*x+1});
                if(c->right) q.push({c->right, 2*x+2});
            }
        }
        return mw;
    }
};