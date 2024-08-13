/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void FillPostorder(string& coded, TreeNode* root){

        if(root == NULL){coded += "N,"; return;}

        FillPostorder(coded, root->left);
        FillPostorder(coded, root->right);

        coded += to_string(root->val) + ",";

    }

    TreeNode* decode(string& data, int& index){
        
        if(index < 0){return NULL;}

        string current;

        while(index >= 0 && data[index] != ','){
            current += data[index--];
        }

        index--;
        
        if(current == "N"){
            return NULL;
        }
        
        reverse(current.begin(), current.end());
        int val = stoi(current);
        TreeNode* root = new TreeNode(val);
        root->right = decode(data, index);
        root->left = decode(data,index);

        return root;    
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){return "";}
        string coded;
        FillPostorder(coded, root);

        coded.pop_back(); //rmemove the last comma
        cout << coded;
        return coded;
    }

    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = data.length()-1;
        return decode(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));