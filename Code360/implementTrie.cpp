/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */


class TrieNode{
public:

    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {

TrieNode* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        //if has corresponding child node
        if(root->children[index]){
            child = root->children[index];
        }
        else{//otherwise create one
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child = root->children[index];

        //if has corresponding child node
        if(child){
            return searchUtil(child, word.substr(1));
        }
        else{//otherwise not found word
            return false;
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }

    bool StartsWithUtil(TrieNode* root, string prefix){
          //base case
        if(prefix.length() == 0){
            return true;
        }

        int index = prefix[0] - 'a';
        TrieNode* child;

        //if has corresponding child node
        if(root->children[index]){
            child = root->children[index];
            return StartsWithUtil(child, prefix.substr(1));
        }
        else{//otherwise not found word
            return false;
        }
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return StartsWithUtil(root, prefix);
    }
};