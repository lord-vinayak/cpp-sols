class Solution {
public:
    bool check(int mid, auto nums, int k){
        int n = nums.size();
        int i = 0, j = 0, count = 0;
        while(i<n || j<n){
            while(j<n && nums[j]-nums[i]<=mid) j++;
            count += j-i-1;
            i++;
        }
        return count>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0 , hi = nums[(nums.size()-1)] - nums[0];
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid, nums, k)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};