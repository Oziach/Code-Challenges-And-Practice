
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>

using namespace std;

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

class Trie{

public:

    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }
    

    void InsertUtil(TrieNode* root, string word){
        
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assuming words are all caps

        //if has character child,
        int index = word[0]-'A'; 
        TrieNode* child;
        
        if(root->children[index]){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }


        InsertUtil(child, word.substr(1));

    }

    void InsertWord(string word){
        InsertUtil(root, word);
    }
    
    
    bool SearchUtil(TrieNode* root, string word){
        
        if(word.length() == 0){
            return root->isTerminal;
        }
        
        
        int index = word[0] - 'A';
        TrieNode* child = root->children[index];
        
        if(child){
            return SearchUtil(child, word.substr(1));
        }
        else{
            return false;
        }
    }

    bool Search(string word){
        return SearchUtil(root, word);
    }
};

int main(){
    Trie* t = new Trie();
    t->InsertWord("ABCD");
    cout << t->Search("ABCDE");
}