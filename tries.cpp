//trie
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    // Creating a blueprint for each node of the trie.
    public:
    char data;//Stores the character of the node.
    TrieNode* children[26];//Array of 26 pointers. Each index represents a lowercase letter:
    bool isTerminal;

    TrieNode(char ch){ //Constructor runs whenever a node is created.
        data = ch; //ch is the character stored in node.
        for(int i = 0;i <26;i++){ //initially no child exists.
            children[i]= NULL;
        }
        isTerminal = false;
    }
};

class Trie{ //This class manages the whole trie.
    public:
    TrieNode* root;
    // Pointer to root node.
    // Root is the starting node of trie.

    Trie(){
        root = new TrieNode('\0'); //Runs when Trie object is created.
    }

    void insertUtil(TrieNode* root, string word) {
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            // Mark current node as end of word.
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;//Pointer to next child node.

        //present
        if(root->children[index]!=NULL){//Check if Character Already Present
            child = root->children[index];
        }
        else{//absent;
            child = new TrieNode(word[0]); //Create new node for current character.
            root->children[index] = child;
            // Connect new node to parent.
        }

        //recursion

        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root, string word) {
        //base case
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }

    void removeUtil(TrieNode* root, string word){

        // base case
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';

        TrieNode* child = root->children[index];

        // if word not present
        if(child == NULL){
            return;
        }

        // recursion
        removeUtil(child, word.substr(1));
    }

    bool prefixUtil(TrieNode* root, string word){

    // base case
        if(word.length() == 0){
            return true;
        }

        int index = word[0] - 'a';

        TrieNode* child;

        // present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        // recursion
        return prefixUtil(child, word.substr(1));
    }


    void removeWord(string word){
        removeUtil(root, word);
    }

    bool search(string word){
        return searchUtil(root, word);
    }

    bool startsWith(string prefix){
        return prefixUtil(root, prefix);
    }

    
};



int main(){
    Trie* t = new Trie();
    t->insertWord("helloduniya");
    string s = "hello";
    cout<<t->search("hello");


     

    return 0;
}