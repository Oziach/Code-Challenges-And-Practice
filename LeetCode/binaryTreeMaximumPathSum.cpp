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
private:
    int SetMaxPathSum(TreeNode* root, int& maxi){

        if(root == NULL){return 0;}

        int leftSum = SetMaxPathSum(root->left, maxi);
        int rightSum = SetMaxPathSum(root->right, maxi);

        int currVal = root->val;

        maxi = max(maxi, leftSum + rightSum + currVal);
        maxi = max(maxi, leftSum + currVal);
        maxi  = max(maxi, rightSum + currVal);
        maxi = max(maxi, currVal);

        return max(root->val, max(leftSum + root->val, rightSum + root->val));

    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = root->val;
        SetMaxPathSum(root, maxi);

        return maxi;
    }
};