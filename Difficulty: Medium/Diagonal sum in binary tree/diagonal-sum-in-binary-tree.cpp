/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

class Solution {
  public:
  void diag(Node* root, int d, auto &mp){
      if(root==nullptr) return;
      mp[d] += root->data;
      diag(root->left, d+1, mp);
      diag(root->right, d, mp);
      
  }
    vector<int> diagonalSum(Node* root) {
        // Add your code here
        unordered_map<int,int> mp;
        diag(root, 0 , mp);
        vector<int> ans;
        for(int i=0; i<mp.size(); i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};