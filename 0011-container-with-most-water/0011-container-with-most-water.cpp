class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0,i=0,j=height.size()-1,minWater=INT_MAX;
        while(i<j){
            minWater=min(height[i],height[j]);
            water=max(water,minWater*(j-i));
            height[i]<height[j] ? i++:j--;
        }
        return water;
    }
};