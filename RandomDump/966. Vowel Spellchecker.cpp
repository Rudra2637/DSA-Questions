#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool vowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')  return true;
        return false;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string>ans;
        unordered_set<string>s;
        unordered_map<string,string>mp;
        unordered_map<string,string>m;

        for(int i=0;i<wordlist.size();i++){
            s.insert(wordlist[i]);
            string a = wordlist[i];
            transform(a.begin(), a.end(), a.begin(), ::toupper);
            if(mp.find(a) == mp.end()) mp[a] = wordlist[i];
            int j=0;
            
            while(wordlist[i].size() > j){
                if(vowel(a[j])){
                    a[j] = '*';
                }
                j++;
            }
            if(m.find(a) == m.end()) m[a] = wordlist[i];
        }
        // for(auto it:mp)cout<<it.first<<" "<<it.second<<endl;
        // cout<<"Now the vowels "<<endl;

        // for(auto it:m)cout<<it.first<<" "<<it.second<<endl;


        for(auto it:queries){
            if(s.find(it) != s.end()){
                ans.push_back(it);
            }
            else  {
                string a = it;
                transform(a.begin(), a.end(), a.begin(), ::toupper);
                if(mp.find(a) != mp.end())ans.push_back(mp[a]);
                else{
                    int j=0;
                    while(it.size() > j){
                        if(vowel(a[j])){
                            a[j] = '*';
                        }
                        j++;
                    }
                    if(m.find(a) != m.end())ans.push_back(m[a]);
                    else ans.push_back("");
                }
            }
        }
        return ans;
    }
};