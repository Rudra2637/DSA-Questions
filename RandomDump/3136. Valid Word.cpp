#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        // Check only allowed characters
        for(char c : word) {
            if(!((c >= '0' && c <= '9') || 
                 (c >= 'a' && c <= 'z') || 
                 (c >= 'A' && c <= 'Z')))
                return false;
        }

        // Check at least one vowel
        bool hasVowel = false;
        for(char c : word) {
            char lower = tolower(c);
            if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                hasVowel = true;
                break;
            }
        }
        if(!hasVowel) return false;

        // Check at least one consonant
        bool hasConsonant = false;
        for(char c : word) {
            char lower = tolower(c);
            if((lower >= 'a' && lower <= 'z') && 
               !(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')) {
                hasConsonant = true;
                break;
            }
        }
        if(!hasConsonant) return false;

        return true;
    }
};
