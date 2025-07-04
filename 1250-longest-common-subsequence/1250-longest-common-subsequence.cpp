class Solution {
public:
int dp[1001][1001];
int lcs(string x, string y, int m, int n){
    if(n==0||m==0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(x[m-1]==y[n-1]) return dp[m][n] = 1+lcs(x,y,m-1,n-1);
    else return dp[m][n] = max(lcs(x,y,m-1,n), lcs(x,y,m,n-1));
}
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        // memset(dp, -1, sizeof(dp));
        // return lcs(text1, text2, m, n);
        //TLE on memoization 46/47 TC passed
        dp[m+1][n+1];
        for(int i=0; i<m+1;i++) dp[i][0] = 0;
        for(int i=0; i<n+1;i++) dp[0][i] = 0;
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(text1[i-1]==text2[j-1])dp[i][j] = 1+dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];

    }
};