class Solution {
public:
    int dp[205][205];
    int fxn(int m, int n,vector<vector<int>>& grid) {
        int ans = INT_MAX;

        if (m == 0 && n == 0)
            return grid[m][n];
        // if(n==0) return grid[m][0];

        // ans = min(grid[m-1][n]+ans,ans);
        // ans = min(grid[m][n-1]+ans,ans);
        // ans = min(fxn(m-1,n)+grid[m][n],ans);
        // ans = min(fxn(m,n-1)+grid[m][n],ans);
        if (dp[m][n] != -1)
            return dp[m][n];
        if (m == 0)
            return dp[m][n] = grid[m][n] + fxn(m, n - 1,grid);
        if (n == 0)
            return dp[m][n] = grid[m][n] + fxn(m - 1, n,grid);
        ans = grid[m][n] + min(fxn(m - 1, n,grid), fxn(m, n - 1,grid));
        return dp[m][n] = ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        // 	for(auto row:grid){
        // 	for(auto pos:row)
        // 		cout<<pos;
        // 	cout<<endl;
        // }

        int m = grid.size();
        int n = grid[m - 1].size();
        return fxn(m - 1, n - 1, grid);
    }
};