///(pre-order traversal)
////////////////sl1//////////////////
class Solution
{
    public:
    void flatten(Node *root)
    {
        while(root != NULL){
            
            if(root->left){
                Node* pred = root->left;
                while(pred->right != NULL && pred->right != root){
                    pred = pred->right;
                }
                
                pred->right = root->right;
                root->right = root->left;
                root->left = NULL;
                
            }
            
            root = root->right;
        }   
    }
};


////////////sol2//////////
public:
    void flatten(Node *root)
    {
        Node* dummyHead = new Node();
        Node* dummy = dummyHead;
        
        while(root != NULL){
            if(!root->left){
                
                dummy->left = root;
                dummy = root;
                
                root = root->right;
            }
            else{
                Node* pred = root->left;
                //find pred
                while(pred->right != NULL && pred->right != root)
                    pred = pred->right;
                    
                if(!pred->right){
                    pred->right = root;

                    dummy->left = root;
                    dummy = root;
                    
                    root = root->left;
                }
                else{
                    pred->right = NULL;
                    root = root->right;
                }
            }
        }
        
        
        root = dummyHead->left;
        while(root != NULL){
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }