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

      int GetCount(TreeNode* root){
        
        if(root == NULL) {return 0;}
        
        return 1 + GetCount(root->left) + GetCount(root->right);
    }
    
    bool IsCBT(TreeNode* root, int index, int n){
        
        if(root == NULL){return true;}
        
        if(index > n){return false;}
        
        return IsCBT(root->left, 2*index, n) && IsCBT(root->right, 2*index + 1, n);
    }
    
    bool isCompleteTree(TreeNode* root) {
        return IsCBT(root, 1, GetCount(root));
    }
};