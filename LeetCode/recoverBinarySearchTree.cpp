/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* ReverseInorder(TreeNode* root, TreeNode*& prev){
        
        if(root == NULL){return NULL;}

        TreeNode* wrongNode = ReverseInorder(root->right, prev);

        if(wrongNode){return wrongNode;}
        if(prev && root->val > prev->val){
            return prev;
        }
        cout << root->val << endl;
        prev = root;
    

        return ReverseInorder(root->left, prev);
    }


    TreeNode* Inorder(TreeNode* root, TreeNode*& prev){
        if(root == NULL){return NULL;}

        TreeNode* wrongNode = Inorder(root->left, prev);
        if(wrongNode){return wrongNode;}

        if(prev && root->val < prev->val){
            return prev;
        }
        prev = root;

        return Inorder(root->right, prev);

    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode* ele1 = NULL;
        TreeNode* ele2 = NULL;

        TreeNode* prev = NULL;

        ele1 = Inorder(root, prev);

        // if(ele1 == NULL){
        //     ele1 = root;
        //     while(ele1->left){
        //         ele1 = ele1->left;
        //     }
        // }


        prev = NULL;
        ele2 = ReverseInorder(root, prev);

        // if(ele2 == NULL){
        //     ele2 = root;
        //     while(ele2->right){
        //         ele2 = ele2->right;
        //     }
        // }

        swap(ele1->val, ele2->val);
    }
};