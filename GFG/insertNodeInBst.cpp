class Solution
{
    public:
        Node* insert(Node* root, int data) {
            
            Node* node = root;
            Node* prev = NULL;
            
            if(!node){return new Node(data);}
            
            while(node){
                
                prev = node;
                
                if(node->data < data){
                    node = node->right;
                }
                else if(node->data > data){
                    node = node->left;
                }
                else{
                    return node;
                }
            }
            
            if(prev->data > data){
                prev->left = new Node(data);
            }
            else{
                prev->right = new Node(data);
            }
            
            return root;
        }

};