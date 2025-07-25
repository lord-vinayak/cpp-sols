class Solution {
public:
    bool check(int mid, auto bloom, int m, int k){
        int bo = 0, fl = 0;
        for(auto b:bloom){
            if(b>mid) fl = 0;
            else{
                bo += (fl+1)/k;
                fl = (fl+1)%k;
            }
        }
        return bo>=m;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        if((long long) bloom.size()<(long long) m*k) return -1;
        int lo = 1, hi = INT_MIN;
        for(int day:bloom) hi = max(hi, day);
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid, bloom, m, k)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};