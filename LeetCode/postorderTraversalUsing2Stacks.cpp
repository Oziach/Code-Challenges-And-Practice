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
    vector<int> postorderTraversal(TreeNode* root) {
        
         vector<int> ans;
        if(root == NULL){return ans;}
        
        stack<TreeNode*> st;
        stack<TreeNode*> st2;

        st.push(root);

        while(!st.empty()){
            TreeNode* top = st.top();
            st.pop();
            
            st2.push(top);

            if(top->left) st.push(top->left);
            if(top->right) st.push(top->right);

        }

        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};