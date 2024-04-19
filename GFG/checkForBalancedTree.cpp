class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node* root){
        if(root == NULL){return 0;}
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(abs(leftHeight - rightHeight) > 1)
            return -1;
        if(leftHeight == -1 || rightHeight == -1)
            return -1;
            
        //else
        return max(leftHeight, rightHeight) + 1;
        
    }
    
    bool isBalanced(Node *root)
    {
        return height(root) == -1 ? false : true;
    }
};