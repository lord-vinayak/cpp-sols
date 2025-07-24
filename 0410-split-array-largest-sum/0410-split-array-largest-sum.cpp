class Solution {
public:
bool ok(int c, auto nums, int k){
        int total = 0, cnt = 1;
        for(auto w:nums){
            total+=w;
            if(total>c){
                total = w;
                cnt+=1;
                if(cnt>k) return false;
            }
        }
        return true;
    }
        
    int splitArray(vector<int>& nums, int k) {
        int lo = INT_MIN, hi = 0;
        for(auto w:nums){
            lo = max(lo, w);
            hi += w;
        }
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(ok(mid, nums, k)){
                hi = mid;
            }
            else lo = mid+1;
        }
        return lo;
    }
};