class Solution {
public:
    int dp[46];
    int fxn(int n) {
        if (n <= 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n]=fxn(n - 1) + fxn(n - 2);
    }
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return fxn(n);
    }
};