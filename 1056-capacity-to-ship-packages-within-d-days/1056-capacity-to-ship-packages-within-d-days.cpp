class Solution {
public:
    bool ok(int c, auto weights, int days){
        int total = 0, day = 1;
        for(auto w:weights){
            total+=w;
            if(total>c){
                total = w;
                day+=1;
                if(day>days) return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = INT_MIN, hi = 0;
        for(auto w:weights){
            lo = max(lo, w);
            hi += w;
        }
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(ok(mid, weights, days)){
                hi = mid;
            }
            else lo = mid+1;
        }
        return lo;
    }
};