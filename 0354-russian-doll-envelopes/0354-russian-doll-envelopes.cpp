class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), comp);
        int i, j, n = env.size();
        vector<int> res;

        for (i = 0; i < n; i++) {
            auto it = lower_bound(res.begin(), res.end(), env[i][1]);
            if (it == res.end())
                res.push_back(env[i][1]);
            else
                *it = env[i][1];
        }
        return res.size();
    }
};