class Solution {
public:
    int maxArea(vector<int>& height) {
         int area= 0;
	int lower=0;
	int upper  = height.size()-1;
	while(lower<upper)
		{
			int mini = min(height[lower], height[upper]);
			if((mini*(upper-lower))>area)
			{	area = (mini*(upper-lower));
            }
			if(height[lower]<height[upper])
				{lower++;}
			else
				{upper--;}
		}
		return area;
    }
};