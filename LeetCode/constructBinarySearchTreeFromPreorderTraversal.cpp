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
    void place(TreeNode* root, int data){
        if(data < root->val){
            if(!root->left){
                root->left = new TreeNode(data);
            }
            else{
                place(root->left, data);
            }
        }

        else if(data > root->val){
            if(!root->right){
                root->right = new TreeNode(data);
            }
            else{
                place(root->right, data);
            }
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            place(root, preorder[i]);
        }

        return root;
    }
};