class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        map<int,int>mp;
        for (int x: b1)
            mp[x]++;
        for (int x: b2)
            mp[x]--;
        
        int t = mp.begin()->first;
        
        vector<int>a;
        for (auto [k,v]: mp)
        {
            if (v%2!=0) return -1;
            if (v>0)
            {
                for (int i=0; i<v/2; i++)
                    a.push_back(k);
            }
            else
            {
                for (int i=0; i<abs(v/2); i++)
                    a.push_back(k);
            }
        }
        
        sort(a.begin(), a.end());
        
        int n = a.size();
        long long ret = 0;
        for (int i=0; i<n/2; i++)
            ret += min(a[i], 2*t);
        
        return ret;
    }
};