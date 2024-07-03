class Solution {
  public:
    vector <int> rightView(Node *root) {
        map<int, int> m;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        while(!q.empty()){
            
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            m[level] = node->data;
            
            if(node->left){q.push({node->left, level+1});}
            if(node->right){q.push({node->right, level+1});}
        }
        
        vector<int> ans;
        for(pair<int,int> p : m){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};

//ver2
class Solution2 {
  public:
    vector <int> rightView(Node *root) {
        map<int, int> m;
        queue<Node*> q;
        
        q.push(root);
        int level = 0;
        
        while(!q.empty()){
            int s = q.size();
            while(s--){
            {
                Node* node = q.front();
                q.pop();
                
                m[level] = node->data;
                
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
                }
            }
            level++;
        }
        
        vector<int> ans;
        for(pair<int,int> p : m){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
