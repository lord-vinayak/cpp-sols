class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
	int target=t, arrSum=0;
	for(auto num:nums){
		arrSum = arrSum+num;
	}
	
	int sum = (arrSum-target)/2;
   if(((arrSum - target) % 2 == 1) || (target > arrSum)) return 0;
		
        int dp[n+1][sum+1];
		for(int i=0; i<n+1; ++i){
			for(int j=0; j<sum+1; ++j){
				if(i==0) dp[i][j]=0;
				if(j==0) dp[i][j]=1;
			}
		}
		for(int i=1; i<n+1; ++i){
			for(int j=0; j<sum+1; ++j){
				if(nums[i-1]<=j)
					dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j];
			}
		}
		
		return dp[n][sum];
    }
};