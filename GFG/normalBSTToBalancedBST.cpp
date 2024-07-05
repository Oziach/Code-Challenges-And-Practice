class Solution{
    
    
void PopulateVectorInorder(Node* root, vector<Node*>& v){
    
    if(root == NULL) {return;}

    PopulateVectorInorder(root->left, v);
    v.push_back(root);
    PopulateVectorInorder(root->right, v);
    
}

Node* BuildBst(vector<Node*>& v, int left, int right){

    int mid = left + (right-left)/2;

    if(left > right){return NULL;}

    Node* root = v[mid];

    root->left = BuildBst(v, left, mid-1);
    root->right = BuildBst(v, mid+1, right);

    return root;
}
    
    public:
    
    // Your are required to complete this function
    // function should return root of the modified BST
    Node* buildBalancedTree(Node* root)
    {
        vector<Node*> v;
        PopulateVectorInorder(root, v);
        return BuildBst(v, 0, v.size()-1);
    }
};