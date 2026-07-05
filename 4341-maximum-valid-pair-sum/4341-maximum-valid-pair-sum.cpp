class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
         int left=0,n=nums.size();
        int mx = 0;
        for(int j=k;j<n;j++) {
            left = max(left, nums[j-k]);
            mx = max(mx, left + nums[j]);
        }
        
        return mx;
    }
};