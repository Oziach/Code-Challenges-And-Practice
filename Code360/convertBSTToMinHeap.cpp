#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void PopulateInorder(BinaryTreeNode* root, vector<int>& v){
	
	if(root == NULL){
		return;
	}
	
	PopulateInorder(root->left, v);
	v.push_back(root->data);
	PopulateInorder(root->right, v);
}

void ConvertToPreorderMinHeap(BinaryTreeNode* root, vector<int>& v, int& i){

	if(root == NULL){return;}

	root->data = v[i++];
	ConvertToPreorderMinHeap(root->left, v, i);
	ConvertToPreorderMinHeap(root->right, v, i);
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> v;
	int i = 0;

	PopulateInorder(root, v);
	ConvertToPreorderMinHeap(root, v, i);
	return root;
}