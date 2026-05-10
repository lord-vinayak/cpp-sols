class Solution {
public:
vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};

bool isOK(int d, vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>>vis(n, vector<int>(n, 0));
        
        if (grid[0][0]<=d) return false;
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0] = 1;
        
        while (!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                if (i<0||i>=n||j<0||j>=n) continue;
                if (grid[i][j]<=d) continue;
                if (vis[i][j]) continue;
                
                vis[i][j] = 1; 
                if (i==n-1 && j==n-1) return true;
                q.push({i,j});
            }
        }
        
        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
                
        queue<pair<int,int>>q;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (grid[i][j]==1)
                    q.push({i,j});
        
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto [x,y] = q.front();
                q.pop();
                for (int k=0; k<4; k++)
                {
                    int i = x+dir[k].first;
                    int j = y+dir[k].second;
                    if (i<0||i>=n||j<0||j>=n) continue;
                    if (grid[i][j]!=0) continue;
                    grid[i][j] = grid[x][y]+1;
                    q.push({i,j});
                }
            }
        }
        
        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mid = hi-(hi-lo)/2;
            if (isOK(mid, grid))
                lo = mid;
            else
                hi = mid-1;
        }
        
        return lo;
    }
};