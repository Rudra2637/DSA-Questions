#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // int r = n;
        // int c = 10;
        // // vector<vector<int>> matrix(r, vector<int>(c, 0));
        
        
        // int ans = 0;
        

        // for(int i = 0;i < reservedSeats.size(); i++){
        //     int tempR = reservedSeats[i][0];
        //     int tempC = reservedSeats[i][1];
 
            
        // }

        // // for(auto it:m){
        // //     cout<<it.first<<" "<<it.second<<endl;
        // // }

        // // for(int i=0;i<r;i++){
        // //     unordered_set<int>s;
        // //     for(int j=1;j<=5;j+=2){
                
        // //         if(s.find(j-2) != s.end())continue;
        // //         int cnt = 0;
        // //         int k = j;

        // //         while(cnt < 4){
        // //             if(matrix[i][j] == 1){
        // //                 break;
        // //             } 
        // //             j++;
        // //             cnt++;
        // //         }
        // //         if(cnt == 4){
        // //             // cout<<i<<" "<<j<<" "<<endl;
        // //             ans++;
        // //         }
        // //         j = k;
        // //         if(cnt == 4){
        // //             // cout<<j<<endl;
        // //             s.insert(j);
        // //         }
        // //     }
        // // }
        
        // // cout<<endl<<endl;
        // // for(int i=0;i<r;i++){
        // //     for(int j=0;j<c;j++){
        // //         cout<<matrix[i][j]<<" ";
        // //     }cout<<endl;
        // // }

        unordered_map<int,unordered_set<int>>m;
        
        for(int i = 0;i < reservedSeats.size(); i++){
            int tempR = reservedSeats[i][0];
            int tempC = reservedSeats[i][1];
 
            m[tempR].insert(tempC); 
            
        }

        int result = 0;
        int s = m.size();
        result += (n-s) * 2;

        for(auto& [row, bookedSeats] : m) {

            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) & isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) & isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) & isAvailable(9);

            if(groupA && groupC)
                result += 2;
            else if(groupA || groupB || groupC)
                result += 1;

        }

        return result;
    }
};