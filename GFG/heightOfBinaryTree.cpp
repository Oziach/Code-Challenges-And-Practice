class Solution{
    public:
    
    void solve(struct Node* root, int& height, int& maxHeight){
        //update height
        height++;
        if(height>maxHeight){maxHeight = height;}
        
        if(root->left){
            solve(root->left, height, maxHeight);
            height--;
        }
            
        if(root->right){
            solve(root->right, height, maxHeight);
            height--;
        }
        
    }
    
    //Function to find the height of a binary tree.
    int height(struct Node* node){
         int h = 0;
         int maxHeight = 0;
         solve(node, h, maxHeight);
         
         return maxHeight;
    }
    
};