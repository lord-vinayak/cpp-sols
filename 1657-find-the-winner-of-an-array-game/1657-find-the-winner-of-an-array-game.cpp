class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxx = arr[0];
        int t = 0;
        for (int i=1; i<arr.size(); i++)
        {
            if (arr[i]>maxx)
            {
                maxx = arr[i];
                t = 1;
            }
            else   t+=1;
            if (t == k) return maxx;
        }
        return maxx;
    }
};