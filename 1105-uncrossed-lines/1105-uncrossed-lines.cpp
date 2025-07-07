class Solution {
public:
int lcs(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
        if(i>=nums1.size() || j>=nums2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(nums1[i]==nums2[j]){
            ans=1+lcs(nums1,nums2,i+1,j+1,dp);
        }
        ans=max({ans,lcs(nums1,nums2,i+1,j,dp),lcs(nums1,nums2,i,j+1,dp)});
        return dp[i][j]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return lcs(nums1,nums2,0,0,dp);
    }
};