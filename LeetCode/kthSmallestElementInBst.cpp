class Solution {

public:
    int kthSmallest(TreeNode* root, int& k) {
        
        if(root == NULL){return -1;}
        
        int ans = kthSmallest(root->left, k);
        if(k == 0) return ans;

        k--;
        if(k == 0){return root->val;}

        ans = kthSmallest(root->right, k);
        return ans;
    }
};c