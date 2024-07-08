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
    void insert(string word) { insertUtil(root, word); }

    void PrintSuggestions(TrieNode* curr, vector<string>& temp, string prefix){

        if(curr->isTerminal){
            temp.push_back(prefix + curr->data);
        }

        TrieNode* child;
        for(int i = 0; i < 26; i++){
            child = curr->children[i];
            if(child){
                PrintSuggestions(child, temp, prefix + curr->data);
            }
        }
    }

    vector<vector<string>> GetSuggestions(string str){
        TrieNode* prev = root;
        vector<vector<string>> output;  
        string prefix = "";

        for(int i = 0; i < str.size(); i++){
            char lastCh = str[i];

            //check for last ch
            TrieNode* curr = prev->children[lastCh - 'a'];

            if(curr == NULL){
                break;
            }
            else{//if found
                vector<string> temp;
                PrintSuggestions(curr, temp, prefix);

                output.push_back(temp);
                temp.clear();
                prev = curr;
            }
            
            prefix += lastCh;
        }

        return output;
    }

};

vector<vector<string>>
phoneDirectory(vector<string> &contactList, string &queryStr) {
    Trie* t = new Trie();

    for(int i = 0; i < contactList.size(); i++){
        string str = contactList[i];
        t->insert(str);
    }

    return t->GetSuggestions(queryStr);
}
