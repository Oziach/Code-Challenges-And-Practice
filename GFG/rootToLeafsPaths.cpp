class Solution {
  private:
  void AddPath(Node* root, vector<int>& path, vector<vector<int>>& ans){
      
      if(root == NULL){return;}
      if(root->left == NULL && root->right == NULL){
          path.push_back(root->data);
          ans.push_back(path);
          path.pop_back();
      }
      
      path.push_back(root->data);
      
      AddPath(root->left, path, ans);
      AddPath(root->right, path, ans);
      
      path.pop_back();
      
  }
  
  public:
    vector<vector<int>> Paths(Node* root) {
        
        vector<int> path;
        vector<vector<int>> ans;
        
        AddPath(root, path, ans);
        
        return ans;
    }
};