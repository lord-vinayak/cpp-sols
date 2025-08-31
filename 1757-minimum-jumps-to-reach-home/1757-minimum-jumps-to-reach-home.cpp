class Solution {
public:
    unordered_map<int, int> mp;
    int dp[6001][2];
    int solve(int i, bool flag, int a, int b, int x){
        if(i==x) return 0;
        if((i<0)|| mp.find(i)!=mp.end()||(i>6000)) return 1e9;
        if(dp[i][flag]!=-1) return dp[i][flag];
        dp[i][flag] = 1+solve(i+a, 0, a, b, x);
        if(!flag) dp[i][flag] = min(dp[i][flag], 1+solve(i-b, 1, a, b, x));
        return dp[i][flag];
    }
    int minimumJumps(vector<int>& forb, int a, int b, int x) {
        for (auto x : forb)
            mp[x] = 1;
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, a, b, x);
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};