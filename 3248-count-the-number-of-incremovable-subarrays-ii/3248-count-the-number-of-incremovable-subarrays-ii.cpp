class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& arr) {
        long long n = arr.size();
        // long long res = n-1;
        
        long long j = n-1;
        while (j-1>=0 && arr[j-1]<arr[j])
            j--;
        // res = j;        
        if (j == 0) return n * (n + 1) / 2;
        long long res = n - j + 1;
        
        for (long long i=0; i<n; i++)
        {
            if (i>=1 && arr[i]<=arr[i-1]) break;
            while (j<n && arr[j]<=arr[i])
                j++;
            res += n - j + 1; 
        }
        
        return res;
    }
};