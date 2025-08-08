#include<bits/stdc++.h>
using namespace std;
 struct ListNode {
    int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-heap
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;
        int k = lists.size();

        for(int i=0;i<k;i++){
            if(lists[i] != NULL)min_heap.push(lists[i]);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!min_heap.empty()){
            ListNode* top = min_heap.top();
            min_heap.pop();

            if(top->next != NULL){
                min_heap.push(top->next);
            }

            if(head == NULL){
                head = top;
                tail = top;
            }
            else{
                tail->next = top;
                tail = top;
            }

        }
        return head;
    }
};