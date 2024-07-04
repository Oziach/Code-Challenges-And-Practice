int solve(BinaryTreeNode<int>* root, int& k){
    //gonna use Morris traversal for practice
    while(root != NULL){
        if(!root->left){
            k--;
            if(k == 0){return root->data;}
            root = root->right;
        }
        else{
            BinaryTreeNode<int>* pred = root->left;
            while(pred->right != NULL && pred->right != root){
                pred = pred->right;
            }

            if(!pred->right){
                pred->right = root;
                root = root->left;
            }
            else{
                pred->right = NULL;
                k--;
                if(k==0){return root->data;}
                root = root->right;
            }
        }
    }

    return -1;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    return solve(root, k);
}