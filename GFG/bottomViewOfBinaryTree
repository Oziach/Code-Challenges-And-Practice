class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int, int> m;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        while(!q.empty()){
            
            Node* node = q.front().first;
            int tier = q.front().second;
            q.pop();
            
            m[tier] = node->data;
            
            if(node->left){q.push({node->left, tier-1});}
            if(node->right){q.push({node->right, tier+1});}
        }
        
        vector<int> ans;
        for(pair<int,int> p : m){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};