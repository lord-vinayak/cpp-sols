class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& rede, vector<vector<int>>& bluee) {
    int INF = 1e9;
    vector<int> red(n, INF), blue(n, INF);

    blue[0] = 0, red[0] = 0;

    for(int i=0;i<n;i++){
        for(auto &e: rede){
            if(red[e[1]] > (blue[e[0]] + 1)){
                red[e[1]] = (blue[e[0]] + 1);
            }
        }
        for(auto &e: bluee){
            if(blue[e[1]] > (red[e[0]] + 1)){
                blue[e[1]] = (red[e[0]] + 1);
            }
        }
    }
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        ans[i] = min(blue[i], red[i]);
        if(ans[i]==INF) ans[i] = -1;
    }
    return ans;
    }
};