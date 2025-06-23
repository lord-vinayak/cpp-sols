class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<int> color(n);

        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while (!q.empty()) {
                    int f = q.front();
                    q.pop();
                    for (int j : graph[f]) {
                        if (vis[j]) {
                            if (color[j] == color[f])
                                return false;
                        } else {
                            color[j] = -color[f];
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};