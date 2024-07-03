class Solution{
    private:
    pair<int,int> solve(Node* root){
        
        if(root == NULL){return {0,0};}
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns = solve(root->right);
        
        int thisAnsInclude = 0;
        int thisAnsExclude = 0;
        
        //include
        thisAnsInclude += root->data + leftAns.second + rightAns.second;
        
        //exclude
        thisAnsExclude += max(leftAns.first, leftAns.second) 
            + max(rightAns.first, rightAns.second);
        
        return {thisAnsInclude, thisAnsExclude};
        
    }
    
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int> p = solve(root);
        return max(p.first, p.second);
    }
};