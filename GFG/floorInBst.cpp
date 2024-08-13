class Solution{

public:
    int floor(Node* root, int x) {
        int floor = -1;
        while(root){
            if(root->data > x){
                root = root->left;
            }
            else{
                floor = root->data;
                root = root->right;
            }
        }
        
        return floor;
    }
};