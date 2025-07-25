class Solution {
public:
    bool ok(int mid, auto nums, int h){
        int hours = 0;
        for(auto w:nums){
            hours = hours + w/mid;
            if(w%mid != 0) hours++;
        }
        return (hours<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = INT_MIN;
        for(auto w:piles){
            hi = max(hi, w);
        }
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(ok(mid, piles, h)){
                hi = mid;
            }
            else lo = mid+1;
        }
        return lo;
    }
};