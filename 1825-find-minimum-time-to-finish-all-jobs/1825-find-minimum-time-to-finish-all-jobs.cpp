class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        int m = 1 << n;

        vector<int> sum(m, 0);
        for (int mask = 1; mask < m; mask++) {
            int bit = __builtin_ctz(mask);// index of lowest set bit
            sum[mask] = sum[mask ^ (1 << bit)] + jobs[bit];
        }

        vector<vector<int>> dp(k + 1, vector<int>(m, INT_MAX));
        dp[0][0] = 0;

        for (int worker = 1; worker <= k; worker++) {
            dp[worker][0] = 0;
            for (int mask = 1; mask < m; mask++) {
                for (int sub = mask; sub; sub = (sub - 1) & mask) {
                    dp[worker][mask] = min(
                        dp[worker][mask],
                        max(dp[worker - 1][mask ^ sub], sum[sub])
                    );
                }
            }
        }

        return dp[k][m - 1];
    }
};