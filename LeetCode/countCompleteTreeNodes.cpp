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
    int countNodes(TreeNode* root) {
        if(root == NULL){return 0;}
        
        int left = FindLeftTreeHeight(root);
        int right = FindRightTreeHeight(root);

        if(left == right){
            return (1 << (left+1)) - 1; //2 to power n - 1
        }
        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

    int FindLeftTreeHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }

        return height;
    }

    int FindRightTreeHeight(TreeNode* root){
        int height = 0;
        root = root->right;
        while(root){
            height++;
            root = root->right;
        }

        return height;
    }
};/**
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
    int countNodes(TreeNode* root) {
        if(root == NULL){return 0;}
        
        int left = FindLeftTreeHeight(root);
        int right = FindRightTreeHeight(root);

        if(left == right){
            return (1 << (left+1)) - 1; //2 to power n - 1
        }
        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

    int FindLeftTreeHeight(TreeNode* root){
        int height = 0;
        while(root){
            height++;
            root = root->left;
        }

        return height;
    }

    int FindRightTreeHeight(TreeNode* root){
        int height = 0;
        root = root->right;
        while(root){
            height++;
            root = root->right;
        }

        return height;
    }
};