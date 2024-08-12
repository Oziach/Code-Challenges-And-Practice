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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root){return ans;}


        map<int,int> m;

        queue<TreeNode*> q;
    
        q.push({root});
        int currLevel = 0;

        while(!q.empty()){

            int s = q.size();

            while(s--){

                TreeNode* currNode = q.front();
                q.pop();
                
                m[currLevel] = currNode->val;

                if(currNode->left){q.push(currNode->left);}
                if(currNode->right){q.push(currNode->right);}
            }
            
            currLevel++;
        }

        for(auto p : m){
            ans.push_back(p.second);
        }
        return ans;
    }
};