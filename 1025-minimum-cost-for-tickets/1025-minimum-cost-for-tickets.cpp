class Solution {
public:
    bool travel[366];
    int dp[366];
    int fxn(int i,vector<int>& costs) {

        // we stored which days we are travelling
        if (i > 365)
            return 0;
        int ans = INT_MAX;

        if (!travel[i]) {
            return fxn(i + 1, costs);
        }
        if (dp[i] != -1)
            return dp[i];
        ans = min(ans, fxn(i + 1, costs) + costs[0]);
        ans = min(ans, fxn(i + 7, costs) + costs[1]);
        ans = min(ans, fxn(i + 30, costs) + costs[2]);
        return dp[i] = ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        for (int day : days) {
            travel[day] = true;
        }
        return fxn(0, costs);
    }
};