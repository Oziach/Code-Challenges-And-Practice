class Solution{
    void solve(Node* root, vector<int>& v, int& ans, int k){

        if(root == NULL) return;
        
        v.push_back(root->data);
        solve(root->left, v, ans, k);
        solve(root->right, v, ans, k);
        
        int sum = 0;
        for(int i = v.size()-1; i >= 0; i--){
            sum += v[i];
            if(sum == k) ans++;
        }
        
        v.pop_back();
        
        
    }
    
  public:
    int sumK(Node *root,int k)
    {
     int ans = 0;
     
     vector<int> v;
     
     solve(root, v, ans, k);
     
     return ans;
    }
};