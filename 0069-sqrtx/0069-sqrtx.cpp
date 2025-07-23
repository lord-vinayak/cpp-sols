class Solution {
public:
    int mySqrt(int x) {
        long long y = x;
        long long lo = 0, hi = y+1;
        while(lo<hi){
            long long mid = lo + (hi-lo)/2;
            if(mid*mid>x) hi = mid;
            else lo = mid+1;
        }
        return lo-1;
    }
};