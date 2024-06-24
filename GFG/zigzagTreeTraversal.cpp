class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        
    	stack<Node*> currentSt;
    	stack<Node*> nextSt;
    	vector<int> ans;
    	
    	if(!root) return ans;
    	        
    	bool ltor = false;
    	currentSt.push(root);
    	
    	while(!currentSt.empty())
    	{
    	    int size = currentSt.size();
    	    while(size--)
    	    {
    	        auto node = currentSt.top();
    	        if(!ltor)
    	        {
    	            if(node->left) nextSt.push(node->left);
    	            if(node->right) nextSt.push(node->right);
    	        }
    	        else
    	        {
    	            if(node->right) nextSt.push(node->right);
    	            if(node->left) nextSt.push(node->left);
    	        }
    	        currentSt.pop();
    	        ans.push_back(node->data);
    	    }
    	    ltor = !ltor;
    	    //swap stacks
    	    stack<Node*> temp;
    	    temp = currentSt;
    	    currentSt = nextSt;
    	    nextSt = temp;
    	}
    }
};