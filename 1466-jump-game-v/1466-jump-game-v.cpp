class Solution {
public:
int dp[1001];
    int d;
    int maxJumps(vector<int>& arr, int d) {
        this->d = d;

        int res = 0;
        for (int i=0; i<arr.size(); i++)
        {
            dfs(i, arr);
            res = max(res, dp[i]);            
        }
        return res;
    }
    int dfs(int i, vector<int>&arr)
    {        
        if (dp[i]!=0) return dp[i];

        int res = 1;

        for (int k=1; k<=d; k++)
        {
            if (i+k>=arr.size()) break;
            if (arr[i+k]>=arr[i]) break;
            res = max(res, dfs(i+k, arr)+1);
        }
        for (int k=1; k<=d; k++)
        {
            if (i-k<0) break;
            if (arr[i-k]>=arr[i]) break;
            res = max(res, dfs(i-k, arr)+1);
        }
        dp[i] = res;

        return dp[i];
    }
};