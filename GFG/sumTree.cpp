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

//another
class Solution
{
    private:
    bool sumTree = true;
    
    int solve(Node* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->data;
        if(!sumTree) return 0;
        
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);
        if(root->data != leftSum + rightSum) sumTree = false;
        
        return leftSum + rightSum + root->data;
        
    }
    
    public:
    bool isSumTree(Node* root)
    {
         solve(root);
         return sumTree;
    }
};