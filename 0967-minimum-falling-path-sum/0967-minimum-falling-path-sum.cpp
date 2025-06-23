class Solution {
public:

int fxn(int m,int n,vector<vector<int>>& matrix,vector<vector<int>> &dp){
	// int ans = INT_MAX;
	// if(m==0 && n==0) return matrix[m][n];----> x

	//base condn
	// if(m==0){
	// return matrix[m][n];
	// }
	// if(dp[m][n]!=-1) return dp[m][n];
	// if(n==0){
	// 	//we are in first column
	// 	return matrix[m][n]+min(fxn(m-1,n),fxn(m-1,n+1));
	// }

	//new soln --------

	if(m==0 && n<matrix[0].size() && n>=0) return matrix[m][n];
	if(n>=matrix[0].size()||n<0) return INT_MAX;
	//these are base cases

	if(dp[m][n]!= INT_MAX) return dp[m][n];

	return dp[m][n] = matrix[m][n]+min({fxn(m-1,n,matrix,dp),fxn(m-1,n+1,matrix,dp),fxn(m-1,n-1,matrix,dp)});


	// ans = matrix[m][n]+min({fxn(m-1,n),fxn(m-1,n+1),fxn(m-1,n-1)});
	// return dp[m][n] = ans;---> old code
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(105, vector<int>(105, INT_MAX));
        for (int c = 0; c < n; c++) {
            ans = min(ans, fxn(n - 1, c,matrix,dp));
        }
        return ans;
    }
};