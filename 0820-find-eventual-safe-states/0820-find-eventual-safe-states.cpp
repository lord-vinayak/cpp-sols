class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> indeg(n), res, safe(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            for (auto j : graph[i]) {
                rev[j].push_back(i);
                indeg[i]++;
            }
        }

        for (int i = 0; i < n; i++) {

            if (indeg[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            safe[f] = 1;
            for (auto i : rev[f]) {
                indeg[i]--;
                if (indeg[i] == 0)
                    q.push(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (safe[i])
                res.push_back(i);
        }
        return res;
    }
};