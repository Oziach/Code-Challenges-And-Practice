class Solution {
private:
    TreeNode* CreateBst(vector<int>& preorder, int& index, int maxRange){

        if(index >= preorder.size()){return NULL;}
        if(preorder[index] > maxRange){return NULL;}

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = CreateBst(preorder, index, root->val);
        root->right = CreateBst(preorder, index, maxRange);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
            int index = 0;
            return CreateBst(preorder, index, INT_MAX);
    }
    
};