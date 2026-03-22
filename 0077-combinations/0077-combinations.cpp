class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        helper(n, k, 1, comb);
        return res;
    }
    void helper(int n, int k, int cur, vector<int>& comb) {
        if (comb.size() == k) {
            res.push_back(comb);
            return;
        }

        for (int i = cur; i <= n; i++) {
            comb.push_back(i);
            helper(n, k, i + 1, comb);
            comb.pop_back();
        }
    }
};