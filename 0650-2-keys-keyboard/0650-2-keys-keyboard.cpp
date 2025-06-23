class Solution {
public:
    int dp[1005][1005];
    int fxn(int i, int j, int n) {
        if (i == n)
            return 0;
        if (i > n)
            return INT_MAX / 2;
        if (dp[i][j] != -1)
            return dp[i][j];
        int copy = 2 + fxn(2 * i, i, n);
        int paste = 1 + fxn(i + j, j, n);
        return dp[i][j] = min(copy, paste);
    }
    int minSteps(int n) {
        if (n == 1)
            return 0;
        memset(dp, -1, sizeof(dp));
        return 1 + fxn(1, 1, n);
    }
};