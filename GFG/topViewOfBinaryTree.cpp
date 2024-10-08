
class Solution
{
    public:
    
    vector<int> topView(Node *root)
    {
        queue<pair<Node*, int>> q;
        map<int, int> m;
        
        q.push({root, 0});
        
        while(!q.empty()){
            
            Node* node = q.front().first;
            int tier = q.front().second;
            q.pop();
            
            if(m.find(tier) == m.end()){
                m[tier] = node->data;
            }
            
            if(node->left) q.push({node->left, tier-1});
            if(node->right) q.push({node->right, tier+1});
            
        }
        
        vector<int> ans;
        for(auto p : m){
            ans.push_back(p.second);
        }
        
        return ans;
    }

};
