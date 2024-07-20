class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int data){
      this->data = data;
      left = right = NULL;
  }
};

class Comp{
public:
    bool operator()(const Node* first, const Node* second){
        return first->data > second->data;
    }
};

class Solution
{
public:		
	
	
	void FillInorderTraversal(vector<string>& ans, Node* root, string code){
	    
	    if(!root->left && !root->right){ans.push_back(code); return;}
	    
	    FillInorderTraversal(ans, root->left, code + "0");
	    FillInorderTraversal(ans, root->right, code + "1");
	}
	
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
        priority_queue<Node*, vector<Node*>, Comp> pq;
        
        for(int i = 0; i < N; i++){
            pq.push(new Node(f[i]));
        }
        
        while(pq.size() > 1){
            Node* first = pq.top();
            pq.pop();
            Node* second = pq.top();
            pq.pop();
            
            Node* parent = new Node(first->data + second->data);
            if(first->data <= second->data){
                parent->left = first;
                parent->right = second;
            }
            else{
                parent->left = second;
                parent->right = first;
            }
            
            pq.push(parent);
        }
    
        Node* root = pq.top();
        vector<string> ans;
        FillInorderTraversal(ans, root, "");
        
        return ans;
	}
};