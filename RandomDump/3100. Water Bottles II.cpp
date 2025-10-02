#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;
        
        while(empty >= numExchange){
            empty -= numExchange;
            total += 1;
            empty++;
            numExchange ++;
        }
        return total;
    }
};

