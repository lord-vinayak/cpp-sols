class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> T;

        for (auto p : pre) {
            graph[p[1]].push_back(p[0]);
        }
        vector<int> indeg(n, 0);
        vector<bool> vis(n, false);
        for (auto i : graph) {
            for (auto j : i) {
                indeg[j]++;
            }
        }
        queue<int> q;
        for (int i=0; i<n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
                vis[i] = true;
            }
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            T.push_back(f);
            for (auto j : graph[f]) {
                if (!vis[j]) {
                    indeg[j]--;
                    if (indeg[j] == 0) {
                        q.push(j);
                        vis[j] = true;
                    }
                }
            }
        }
        return T.size() == n;
    }
};