class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heat) 
    {
        sort(heat.begin(),heat.end());
        int result=0;
        
        for (int i=0; i<houses.size(); i++)
        {
            int radius;
            
            auto pos= lower_bound(heat.begin(),heat.end(),houses[i]);
            
            if (pos==heat.begin())
                radius = heat[0]-houses[i];
            else if (pos==heat.end())
                radius = houses[i]-heat.back();
            else
                radius = min(*pos-houses[i], houses[i]-*(pos-1));
                
            result = max(result,radius);
        }
        
        return result;
    }
};