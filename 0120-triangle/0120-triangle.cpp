class Solution {
public:

    
    int fxn(int m, int n, vector<vector<int>>& tri, vector<vector<int>>& dp) {
        // attempt 1 ------------
        //  if(m==0 && n<tri[0].size() && n>=0) return tri[m][n];
        //  if(n>=tri[m].size() || n<0) return INT_MAX;
        //  int up = tri[m][n] + fxn(m-1,n);
        //  int left = tri[m][n] + fxn(m-1,n-1);
        //  return min(up, left);

        // attempt 2 ------------
        if (m == tri.size() - 1)
            return tri[m][n];
        if (dp[m][n] != INT_MAX)
            return dp[m][n];
        int down = tri[m][n] + fxn(m + 1, n, tri, dp);
        int right = tri[m][n] + fxn(m + 1, n + 1, tri, dp);
        return dp[m][n] = min(down, right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int N = triangle.size();
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        return  fxn(0, 0, triangle, dp);
    }
};