#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    set<int>s;
    stack<int>st;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st.push(x);
        s.insert(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty()){
            int x = st.top();
            st.pop();
            s.erase(x);
        }
        
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        return st.empty() ? -1:st.top();
        
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        return s.empty() ? -1:*begin(s);
    }
};
    