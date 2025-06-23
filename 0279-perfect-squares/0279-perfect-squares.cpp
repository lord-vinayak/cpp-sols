class Solution {
public:
int dp[10005];
	vector<int> perf_sqr;
int fxn(int n){
	if(n==0) return 0;
	int ans = INT_MAX;
	if(dp[n]!=-1) return dp[n];
	// for(int num:perf_sqr){
	// 	if(i-num>=0)
	// 		ans = min(ans+0LL, fxn(i-num)+1LL);
	// }
for (int i = 1; i * i <= n; i++) {
		int square = i * i;
		ans = min(ans, 1 + fxn(n - square));
	}


	return dp[n]= ans;
}
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
	// for(int i=1; i<=n; i++){
	// 	perf_sqr.push_back(i*i);
	// }
	// cout<<perf_sqr.size()<<endl;
	int ans = fxn(n);
	return (ans==INT_MAX)?-1:ans;
	cout<<ans;
    }
};