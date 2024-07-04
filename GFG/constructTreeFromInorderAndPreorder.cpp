class Solution{
    private:
    
    int findPosition(int in[], int element, int inStart, int inEnd){
        for(int i = inStart; i <= inEnd; i++){
            if(in[i] == element){
                return i;
            }
        }   
        return -1;
    }
    
    Node* solve(int in[], int pre[], int& preInd, int inStart, int inEnd, int n){
        
        if(preInd >= n || inStart > inEnd){
            return NULL;
        }
        
        int element = pre[preInd++];
        Node* root = new Node(element);
        int position = findPosition(in, element, inStart, inEnd);
        
        root->left = solve(in, pre, preInd, inStart, position - 1, n);
        root->right = solve(in, pre, preInd, position+1, inEnd, n);
        
        return root;
        
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preInd = 0;
        Node* ans =  solve(in, pre, preInd, 0, n-1, n);
        return ans;
    }
};