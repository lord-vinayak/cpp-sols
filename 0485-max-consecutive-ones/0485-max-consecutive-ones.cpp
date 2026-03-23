class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0 , res = 0;
		
        for(auto num : nums) 
		{
            if(num == 1)
				++cnt;
				
            else
            {
                res = max(cnt, res);
                cnt = 0;
            }
        }
		
        return max(cnt, res) ;
    }
};