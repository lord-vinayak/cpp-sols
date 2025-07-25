class Solution {
public:
    bool check(int mid, int m, int n, int k){
        int ans = 0;
        for(int i = 1; i <= m; i++) 
            ans += min(mid / i, n);
        return ans>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid,m,n,k)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }
};