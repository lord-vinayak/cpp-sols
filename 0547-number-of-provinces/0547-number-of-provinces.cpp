class Solution {
public:
    vector<bool> vis;
    void dfs(vector<vector<int>>& graph, int v) {
        vis[v] = true;
        for (int j : graph[v]) {
            if (vis[j])
                continue;
            dfs(graph, j);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int cc = 0;
        vis = vector<bool>(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(graph, i);
                cc++;
            }
        }
        return cc;
    }
};