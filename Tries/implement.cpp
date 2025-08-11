#include<bits/stdc++.h>
using namespace std;
  
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
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

    void insertUtil(TrieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return ;
        }
        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child,word.substr(1));
    }

    void insertNode(string word){
        insertUtil(root,word);
    }

    bool searchUtil(TrieNode* root,string word){
        if(word.size() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        if(root->children[index] != NULL){
            return searchUtil(root->children[index],word.substr(1));
        }
        else return false;

    }

    bool search(string word){
        return searchUtil(root,word);
    }

    void removeUtil(TrieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = false;
            return ;
        }

        int index = word[0] - 'A';
        
        removeUtil(root->children[index],word.substr(1));
        
    }
    void remove(string word){
        removeUtil(root,word);
        return ;
    }

};

int main(){
    Trie *t = new Trie();
    
    t->insertNode("ABCD");
    t->insertNode("DOG");
    t->insertNode("TIME");
    t->remove("ABCD");
    cout<<"present or Not"<<" "<<t->search("ABCD")<<endl;
    t->insertNode("ABCD");
    cout<<"present or Not"<<" "<<t->search("ABCD")<<endl;
    // cout<<"present or Not"<<" "<<t->search("TIM");
    return 0;
}