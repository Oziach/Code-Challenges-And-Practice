class Solution
{
    
    public:
    bool isSumTree(Node* root){
        return solve(root).first;
    }
    
    pair<bool,int> solve(Node* root)
    {   
        if(root == NULL)
            return make_pair(true, 0);
            
        if(root->left == NULL && root->right == NULL)
            return make_pair(true, root->data);
        
        pair<bool,int> left = solve(root->left);
        pair<bool,int> right = solve(root->right);
        
        int val1 = left.second;
        int val2 = right.second;
        
        if(val1 + val2 == root->data && left.first && right.first)
            return make_pair(true, val1 + val2 + left.second + right.second);
        else
            return make_pair(false,-1);
        
    }
};