class Solution {
public:
    int dp[1001][5];
    int n;
    const int MOD = 1000000007;
    int makeState(int t1, int t2) {
        if (!t1 && !t2)
            return 0;
        if (!t1 && t2)
            return 1;
        if (t1 && !t2)
            return 2;
        return 3;
    }

    int fxn(int i, bool t1, bool t2) {

        if (i == n)
            return 1;
        int state = makeState(t1, t2);
        if (dp[i][state] != -1)
            return dp[i][state];
        bool t3 = i + 1 < n, t4 = i + 1 < n;
        int count = 0;
        if (t1 && t2 && t3)
            count = (count + fxn(i + 1, false, true))% MOD;
        if (t1 && t2 && t4)
            count =( count +fxn(i + 1, true, false))% MOD;
        if (t1 && !t2 && t3 && t4)
            count= (count +fxn(i + 1, false, false))% MOD;
        if (!t1 && t2 && t3 && t4)
            count = (count + fxn(i + 1, false, false))% MOD;
        if (t1 && t2)
            count = (count + fxn(i + 1, true, true))% MOD;
        if (t1 && t2 && t3 && t4)
            count = (count + fxn(i + 1, false, false))% MOD;
        if (t1 && !t2 && t3)
            count = (count + fxn(i + 1, false, true))% MOD;
        if (!t1 && t2 && t4)
            count = (count + fxn(i + 1, true, false))% MOD;
        if (!t1 && !t2)
            count = (count + fxn(i + 1, true, true))% MOD;
        return dp[i][state] = count % MOD;
    }
    int numTilings(int nn) {
        n = nn;
        memset(dp, -1, sizeof(dp));
        return fxn(0, true, true);
    }
};