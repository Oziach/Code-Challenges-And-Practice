class Solution {
  public:
  
    pair<int,int> solve(Node* root){
        
        if(root == NULL){ return make_pair(0,0); }
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        int mid = left.second + right.second + 1;
        
        int height = 1 + max(left.second, right.second);
        int diameter = max(left.first, max(right.first, mid));
        
        return make_pair(diameter, height);
    }
  
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return solve(root).first;
    }
};