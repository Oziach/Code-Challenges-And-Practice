
class Solution{
    private:
    
    int IsSumProperty(Node* root){
        
        if(root == NULL){return 0;}
        if(root->left == NULL && root->right == NULL){return root->data;}
        
        int left = IsSumProperty(root->left);
        int right = IsSumProperty(root->right);
        
        if(root->data == left + right && right != INT_MIN && left != INT_MIN){
            return root->data;
        }
        else{
            return INT_MIN;
        }
            
    }
     
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root){return true;}
        return IsSumProperty(root) != INT_MIN;
    }
};