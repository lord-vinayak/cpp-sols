class Solution {
    int m,n;
    int par[200*200];
    int sz[200*200];

    int Find(int x)
    {
        if (par[x]!=x)
            par[x] = Find(par[x]);
        return par[x];
    }    
    void Union(int x, int y)
    {
        x = par[x];
        y = par[y];
        if (x<y)
        {
            par[y] = x;
            sz[x] += sz[y];
        }
        else 
        {
            par[x] = y;
            sz[y] += sz[x];
        }
    }        
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        vector<vector<int>> grid0 = grid;

        m = grid.size();
        n = grid[0].size();
        for (int i=0; i<m*n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
        for (auto &hit: hits)
            grid[hit[0]][hit[1]] = 0;

        vector<pair<int,int>>dir({{0,1},{0,-1},{-1,0},{1,0}});

        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==0) 
                    continue;

                for (int k=0; k<4; k++)
                {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second; 

                    if (x<0||x>=m||y<0||y>=n) 
                        continue;
                    if (grid[x][y]==0) 
                        continue;                
                    if (Find(i*n+j)!=Find(x*n+y))
                        Union(i*n+j, x*n+y);
                }
            }
        
        vector<int>res;

        for (int t=hits.size()-1; t>=0; t--)
        {
            int i = hits[t][0], j = hits[t][1];            
            if (grid0[i][j]==0) 
            {
                res.push_back(0);
                continue;
            }

            grid[i][j] = 1;
            int count = 0;
            int flag = 0;

            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;

                if (x<0||x>=m||y<0||y>=n) 
                    continue;
                if (grid[x][y]==0) 
                    continue;   

                if (Find(i*n+j)!=Find(x*n+y))                
                {
                    if (Find(x*n+y)>=n)
                        count+=sz[Find(x*n+y)];

                    if (Find(x*n+y)<n || i==0)
                        flag = 1;

                    Union(i*n+j, x*n+y);                    
                }
            }      

            res.push_back(flag==1? count:0);            
        }

        reverse(res.begin(), res.end());

        return res;
    }
};