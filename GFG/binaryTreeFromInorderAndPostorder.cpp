class Solution {
  private:
  
    int FindPosition(int in[], int inStart, int inEnd, int element){
        for(int i = inEnd; i >= inStart; i--){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }    
  
    Node* solve(int in[], int post[], int& postInd, int inStart, int inEnd){
      
        if(postInd < 0 || inStart > inEnd) 
            return NULL;
        
        int element = post[postInd--];
        Node* root = new Node(element);
        int position = FindPosition(in, inStart, inEnd, element);
        
        root->right = solve(in, post, postInd, position+1, inEnd);
        root->left = solve(in, post, postInd, inStart, position-1);
      
        return root;
  }
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        int postInd = n-1;
        Node* ans = solve(in, post, postInd, 0, n-1);
        return ans;
    }
};