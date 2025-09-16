#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>s;
        int cnt = 0;
        for(int i=0;i<brokenLetters.size();i++){
            s.insert(brokenLetters[i]);
        }

        for(int i=0;i<text.size();i++){
            if(s.find(text[i]) != s.end()){
                while(text.size() > i && text[i] != ' ') i++;
            }
            else if(i == text.size() - 1 || text[i] == ' ') cnt++;
        }
        return cnt;
    }
};