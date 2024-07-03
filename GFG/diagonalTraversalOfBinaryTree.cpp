
void foo(Node* node, map<int, vector<int>>& m, int dLevel){
    
    m[dLevel].push_back(node->data);
    
    if(node->left){foo(node->left, m, dLevel+1);}
    if(node->right){foo(node->right, m, dLevel);}
    
}

vector<int> diagonal(Node *root)
{
   map<int, vector<int>> m;
   foo(root, m, 0);
   
    vector<int> ans;
   for(pair<int,vector<int>> p : m){
       for(int num : p.second){
           ans.push_back(num);
       }
   }
   
   return ans;
}