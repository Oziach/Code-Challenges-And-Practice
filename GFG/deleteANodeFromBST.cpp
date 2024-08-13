
Node* GetInorderPred(Node* root){
    root = root->left;
    while(root->right){
        root = root->right;
    }
    return root;
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int x) {
    if(root == NULL){return root;}
    
    if(root->data > x){
        root->left = deleteNode(root->left, x);
    }
    else if(root->data < x){
        root->right = deleteNode(root->right, x);
    }
    else{//root->data == x
        
        //case 1: root is leaf node
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        //if left node is null
        if(root->left == NULL){
            Node* right = root->right;
            delete root;
            return right;
        }
        //if right node is null
        else if(root->right == NULL){
            Node* left = root->left;
            delete root;
            return left;
        }
        
        //if root has two children
        Node* pred = GetInorderPred(root);
        root->data = pred->data; 
        root->left = deleteNode(root->left, pred->data);
        return root;
    }
}