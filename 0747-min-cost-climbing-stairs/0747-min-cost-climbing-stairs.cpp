class Solution {
public:
    const int N = 1e5;
    int dp[1005];

    int fxn(int i, vector<int>& cost){
	int ans=INT_MAX;
    if(i<0) return 0;
	if(i==0) return cost[0];
    if(i==1) return cost[1];
	if(dp[i]!=-1) return dp[i];
	ans=min(ans,fxn(i-1,cost)+cost[i]);
	if(i>1)
		ans = min(ans, fxn(i-2,cost)+cost[i]);
	return dp[i]=ans;
}

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        int n = (int)cost.size();
        return min(fxn(n - 2, cost), fxn(n - 1, cost));
    }
};