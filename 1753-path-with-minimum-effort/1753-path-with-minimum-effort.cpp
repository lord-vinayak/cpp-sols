class Solution {
public:

bool vis[105][105];  
int xdir[4] = {0, 1, -1, 0};  
int ydir[4] = {1, 0, 0, -1};
int rows=0, cols=0;

    void dfs(int x, int y, int limiteff, vector<vector<int>>& heights) {
        if (vis[x][y])
            return;

        vis[x][y] = true;

        if (x == rows - 1 && y == cols - 1)
            return;

        for (int i = 0; i < 4; i++) {
            int newx = x + xdir[i];
            int newy = y + ydir[i];

            if (newx < 0 || newx >= rows || newy < 0 || newy >= cols)
                continue;

            int neweff = abs(heights[x][y] - heights[newx][newy]);
            if (neweff <= limiteff)
                dfs(newx, newy, limiteff, heights);
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        int lo = 0, hi = 1e6;

        while (lo < hi) {
            int mid = (hi + lo) / 2;
            memset(vis, 0, sizeof(vis));
            dfs(0, 0, mid, heights);

            if (vis[rows - 1][cols - 1])
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};