class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int w) {
        long long n = nums.size(), k = (2*w)+1, sum = 0;
        vector<int> res(n, -1);
        if(n<k) return res;
        for(long i = 0; i<n; i++){
            sum += nums[i];
            if(i-k >= 0) sum -= nums[i-k];
            if(i>=k-1) res[i-w] = (long long) sum/k;            
        }
        return res;
        
    }
};