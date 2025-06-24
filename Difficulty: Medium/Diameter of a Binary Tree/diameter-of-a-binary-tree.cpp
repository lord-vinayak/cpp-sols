/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
  int dia(Node*root, int &d){
      if(root==nullptr) return 0;
      int lh = dia(root->left, d);
      int rh = dia(root->right, d);
      d = max(d, lh+rh);
      return max(lh,rh)+1;
  }
    int diameter(Node* root) {
        // Your code here
        int d=0;
        dia(root,d);
        return d;
    }
};