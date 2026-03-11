class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0, end = 0, res = 0, cnt = 0, evens= 0;
        for(end =0; end<nums.size(); end++){
            if(nums[end]%2!=0) { //if odd no. found 
                cnt++;
                evens = 0;
            } 
            while(cnt==k){
                evens++;
                if(nums[start]%2!=0) cnt--;
                start++;
            }
            res = res+evens;

        }
        return res;
    }
};