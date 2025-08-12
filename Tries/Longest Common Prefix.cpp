#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
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

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
            
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string word){
        insertUtil(root,word);
        return ;
    }

    void lpc(string temp,string &ans){
        for(int i=0;i<temp.size();i++){
            char ch = temp[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else break;

            if(root->isTerminal)break;
        }
    }
    
};




string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie* t = new Trie();
    
    for(int i=0;i<arr.size();i++){
        t->insert(arr[i]);
    }

    string temp = arr[0];
    string ans = "";
    t->lpc(temp,ans);
    return ans;
}


// string s = arr[0];
    // string ans = "";

    // for(int i=0;i<s.size();i++){
    //     char ch = s[i];
    //     bool check = false;
    //     for(int j=1;j<arr.size();j++){
    //         string temp = arr[j];
    //         if(s[i] == temp[i]){
    //             check = true;
    //         }
    //         else{
    //             check = false;
    //             break;
    //         }
    //     }
    //     if(check)ans += s[i];
    //     else break;
    // }
    // return ans;