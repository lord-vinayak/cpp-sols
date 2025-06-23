class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
            return 1;
        vector<int> odeg(n+1), indeg(n+1);
        for(auto t:trust){
            odeg[t[0]]++;
            indeg[t[1]]++;
        }
        for(int i=1; i<n+1; i++){
            if(odeg[i]==0 && indeg[i]==n-1)
            return i;
        }
        return -1;
    }
};