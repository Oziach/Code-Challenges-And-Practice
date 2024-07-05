class Solution{
    private:
    
    struct info{
        bool isBST;
        int maxi;
        int mini;
        int size;
    };
    
    info solve(Node* root, int& maxSize){
        
        if(root == NULL){
            return {true, INT_MIN, INT_MAX, 0};
        }
        
        info left = solve(root->left, maxSize);
        info right = solve(root->right, maxSize);
        
        info current; 
        
        current.mini = min(root->data, left.mini);
        current.maxi = max(root->data, right.maxi);
        current.size = left.size + right.size;
        
        if(left.isBST && right.isBST && root->data > left.maxi 
            && root->data < right.mini){
                
            current.isBST = true;
            current.size++;
            maxSize = max(maxSize, current.size);
            
        }
        else{
            current.isBST = false;
        }
        
        return current;
    }
    
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int maxSize = 0;
    	solve(root, maxSize);
    	
    	return maxSize;
    }
};