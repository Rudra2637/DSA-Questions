
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int solve(int n,int x,int y,int z,vector<int>&dp){
	if(n == 0)return 0;
	if (n < 0) return INT_MIN;

	if(dp[n] != -1)return dp[n];
	
	int cutx = 1+solve(n-x,x,y,z,dp);
	int cuty = 1+solve(n-y,x,y,z,dp);
	int cutz = 1+solve(n-z,x,y,z,dp);
	
	
	return dp[n] = max(cutx, max(cuty, cutz));
}
int cutSegments(int n, int x, int y, int z) {
	vector<int>dp(n+1,-1);
	int ans = solve(n,x,y,z,dp);
	if(ans < 0)return 0;

	return ans;
}