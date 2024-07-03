Node* solve(Node* root, int& k, int node){
    
    if(root == NULL) return NULL;
    if(root->data == node){k--; return root;}
    
    Node* left = solve(root->left, k, node);
    if(k == 0){
        k = -1;
        return root;
    }
    
    Node* right = solve(root->right, k, node);
    
    if(k == 0){
        k = -1;
        return root;
    }
    
    if(left){k--; return left;}
    if(right){k--; return right;}
    
    return NULL;

}

// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{   
    Node* ans = solve(root, k, node);
    if(!ans) return -1;
    if(ans->data == node) return -1;
    return ans->data;
    
}