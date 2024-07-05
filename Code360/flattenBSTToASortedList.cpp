void solve(TreeNode<int>* root, TreeNode<int>*& pred){

    if(root == NULL){return;}

    solve(root->left, pred);
    if(pred) pred->right = root;
    if(pred) root->left = NULL;
    pred = root;
    solve(root->right, pred);

}

TreeNode<int>* flatten(TreeNode<int>* root)
{  
    TreeNode<int>* temp = root;
   while(temp->left)
    temp = temp -> left; 
    
    TreeNode<int>* pred = NULL;
    solve(root, pred);
    return temp;
}