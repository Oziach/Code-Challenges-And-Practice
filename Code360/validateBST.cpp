bool validate(BinaryTreeNode<int> *root, pair<int,int> range){

    if(root == NULL) return true;

    if(root->data < range.first || root->data > range.second)
        return false;
    
    bool left = validate(root->left, {range.first, root->data});
    bool right = validate(root->right, {root->data, range.second});

    return left && right;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return validate(root, {INT_MIN, INT_MAX});
}