int findCeil(Node* root, int input) {
        
        int ciel = -1;
        
        while(root){
        
            if(root->data < input){
                root = root->right;
            }
            else{
                ciel = root->data;
                root = root->left;
            }
        }
        
        return ciel;
    
}