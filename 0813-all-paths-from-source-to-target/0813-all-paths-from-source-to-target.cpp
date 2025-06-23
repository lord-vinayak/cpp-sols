class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path, int v) {
        path.push_back(v);
        if (v == graph.size() - 1)
            res.push_back(path);
        else for (auto it: graph[v])
            dfs(graph, res, path, it);
        path.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, res, path, 0);
        return res;
    }
};