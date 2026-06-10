class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n==1) return {1};
        if (n==2) return {2,1};
        
        vector<int>A = beautifulArray((n+1)/2);
        vector<int>B = beautifulArray(n-(n+1)/2);
        vector<int>res;
        for (int x:A) res.push_back(x*2-1);
        for (int x:B) res.push_back(x*2);
        return res;
    }
};