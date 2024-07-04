//the validation on code360 is faulty.
/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int pred = -1;
    int succ = -1;

    while(root->data != key){
        
        if(root->data > key){
            succ = root->data;
            root = root->left;
        }
        else{
            pred = root->data;
            root = root->right;  
        }
    }

    //pred
    TreeNode* leftTree = root->left;
    while(leftTree){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    TreeNode* rightTree = root->right;
    while(rightTree){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}