class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // k = window size
        int cursum = 0;
        double res;

        //first window
        for(int i = 0; i<k; i++){
            cursum += nums[i];
        }
        res = (double)cursum/k;
        //remaining window
        for(int i=k; i<nums.size(); i++){
            int pre = nums[i-k];
            int nex = nums[i];
            cursum += nex;
            cursum -= pre;
            res = max(res, (double)cursum/k);
        }
        return res;
    }
};