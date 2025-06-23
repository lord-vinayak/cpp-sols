class Solution {
public:
int find(int x, vector<int> p) {
 		return p[x] == x ? x : find(p[x],p);
 	}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> p(n+1), ans(2);
        for (int i = 1; i <= n; i++)
            p[i] = i;
        for (int i = 0; i < n; i++) {
            int x = find(edges[i][0],p);
            int y = find(edges[i][1],p);
            if (x != y)
                p[y] = x;
            else {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            }
        }
        return ans;
    }
};