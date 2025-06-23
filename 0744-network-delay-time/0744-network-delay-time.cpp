class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> d(n, vector<int>(n,10000));       
        for (int i = 0; i < n; i++) {
            d[i][i] = 0;
        }
        for (auto t : times) {
            d[t[0] - 1][t[1] - 1] = t[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (d[i][k] < 10000 && d[k][j] < 10000)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        int ans;
        for(int i=0; i<n; i++){
            if (k-1 == i) continue;
            if(d[k-1][i]==10000) return -1;
            ans = max(ans, d[k-1][i]);
        }
        return ans;
    }
};