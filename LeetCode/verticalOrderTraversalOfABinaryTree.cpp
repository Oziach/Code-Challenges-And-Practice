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
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<int>> m;

        queue<pair<TreeNode*, int>> q;
    
        q.push({root, 0});
        int currLevel = 0;

        while(!q.empty()){
            vector<pair<int, int>> v;
            int s = q.size();

            while(s--){
                pair<TreeNode*, int> front = q.front();
                q.pop();

                int nodeIndex = front.second;
                TreeNode* currNode = front.first;

                v.push_back({currNode->val, nodeIndex});
                if(currNode->left){q.push({currNode->left, nodeIndex-1});}
                if(currNode->right){q.push({currNode->right, nodeIndex+1});}
            }
            
            sort(v.begin(), v.end());
            for(pair<int,int> p : v){
                m[p.second].push_back(p.first);
            }
        }

        vector<vector<int>> ans;
        for(pair<int, vector<int>> p : m){
            ans.push_back(p.second);
        }

        return ans;
    }
};