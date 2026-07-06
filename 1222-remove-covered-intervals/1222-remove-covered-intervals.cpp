class Solution {
public:
static bool cmp(vector<int>&a, vector<int>&b)
    {
        if (a[0]!=b[0])
            return a[0]<b[0];
        else
            return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intv) {
        sort(intv.begin(), intv.end(), cmp);
        int i = 0;
        int count = 0;
        while (i<intv.size())
        {
            count++;
            int j=i+1;
            while (j<intv.size() && intv[j][1]<=intv[i][1])
                j++;
            i = j;
        }
        return count;
    }
};