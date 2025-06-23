class Solution {
public:
    int dp[10010];
    int fxn(int amt,vector<int>& coins) {
        if (amt == 0)
            return 0;
        int ans = INT_MAX;
        if (dp[amt] != -1)
            return dp[amt];
        for (int coin : coins) {
            if (amt - coin >= 0)
                ans = min(ans+0LL, fxn(amt - coin, coins) + 1LL);
        }
        return dp[amt] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int res = fxn(amount, coins);
        return res==INT_MAX?-1:res;
    }
};