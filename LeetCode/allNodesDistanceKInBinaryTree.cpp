class Solution {
private:
    void SetParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parents){

        if(root->left){parents[root->left] = root; SetParents(root->left, parents);}
        if(root->right){parents[root->right] = root; SetParents(root->right, parents);}

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;

        unordered_map<TreeNode*, TreeNode*> parents;
        SetParents(root, parents);


        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited[target] = true;

        while(!q.empty()){
            
            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int dist = front.second;

            if(dist == k){
                ans.push_back(node->val);
                continue;
            }

            if(node->left && !visited[node->left]){q.push({node->left, dist+1}); visited[node->left] = true;}
            if(node->right && !visited[node->right]){q.push({node->right, dist+1}); visited[node->right] = true;}
            if(parents[node] && !visited[parents[node]]){q.push({parents[node], dist+1}); visited[parents[node]] = true;}

        }

        return ans;
    }
};