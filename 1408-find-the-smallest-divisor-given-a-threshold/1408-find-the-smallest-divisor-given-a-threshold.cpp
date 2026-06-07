class Solution {
public:
    int smallestDivisor(vector<int>& nums, int thr) {
        int left = 1, right = INT_MAX;
        while (left < right)
        {
            int mid = left+(right-left)/2;
            if (check(mid, nums, thr))
                right = mid;
            else
                left = mid + 1;            
        }
        return left; 
    }
    bool check(int x, vector<int>& nums, int thr)
    {
        int sum = 0;
        for (auto a: nums)
        {
            if (a%x==0)
                sum+=a/x;
            else
                sum+=a/x+1;
        }
        return sum<=thr;
    }
};