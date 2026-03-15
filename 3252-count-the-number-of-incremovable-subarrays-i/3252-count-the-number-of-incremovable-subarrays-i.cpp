class Solution {
public:
    int incremovableSubarrayCount(vector<int>& arr) {
        int n = arr.size();
        // int res = n-1;
        
        int j = n-1;
        while (j-1>=0 && arr[j-1]<arr[j])
            j--;
        // res = j;        
        if (j == 0) return n * (n + 1) / 2;
        int res = n - j + 1;
        
        for (int i=0; i<n; i++)
        {
            if (i>=1 && arr[i]<=arr[i-1]) break;
            while (j<n && arr[j]<=arr[i])
                j++;
            res += n - j + 1; 
        }
        
        return res;

    }
};