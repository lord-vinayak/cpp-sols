class Solution {
public:
vector<vector<int>> graph;
void dfs(int v, vector<int> &res, vector<int>& quiet){
    if(res[v]!=-1) return;
    res[v] = v;
    for(auto j:graph[v]){
        dfs(j, res, quiet);
        if(quiet[res[j]]<quiet[res[v]]) res[v] = res[j];
    }
}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        graph.resize(n);
        for(auto i:richer){
            graph[i[1]].push_back(i[0]);
        }
        vector<int> res(n,-1);
        for(int i=0; i<n; i++) dfs(i,res, quiet);
    return res; 
    }
   
};