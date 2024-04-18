/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/


void getAns(BinaryTreeNode<int>* root, int& count){
    
    if(root->left == NULL && root->right == NULL){
        count++;
        return;
    }

    if(root->left){getAns(root->left, count);}
    if(root->right){getAns(root->right, count);}
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
   int count = 0;
   getAns(root, count);
   return count;
}