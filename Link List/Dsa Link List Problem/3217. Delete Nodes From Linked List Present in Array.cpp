#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        bool checkFirst = false;
        
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]]++;
        

        while(curr != NULL){
            if(mp.find(curr->val) != mp.end()){
                if(!prev){
                    ListNode* temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                }
                else {
                    prev->next = curr->next;
                    curr->next = NULL;
                    curr = prev->next;
                    
                }
            }
            else {
                if(!checkFirst){
                    checkFirst = true;
                    head = curr;
                }
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};