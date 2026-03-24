class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        for(int l = 0, r = 0; r < nums.size() - 1; step++){
        	int rr = 0;
        	for(int i = l; i <= r; i++) rr =  max(rr, i + nums[i]);
        	l = r + 1;
        	r = rr;
        }
        return step;
    }
};