class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, 0, target, path, ans);
    return ans;
  }

  void dfs(const vector<int>& candidates, int s, int target, vector<int>& path,
           vector<vector<int>>& ans) {
    if (target < 0)
      return;
    if (target == 0) {
      ans.push_back(path);
      return;
    }

    for (int i = s; i < candidates.size(); ++i) {
      path.push_back(candidates[i]);
      dfs(candidates, i, target - candidates[i], path, ans);
      path.pop_back();
    }
           }
};