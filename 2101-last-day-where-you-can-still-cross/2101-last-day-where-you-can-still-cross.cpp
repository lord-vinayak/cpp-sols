class Solution {
    vector<int>par;
    public:

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
        if (x<y) par[y] = x;
        else par[x] = y;
    } 
    int m,n;


    bool check()
    {
        return Find(m*n)==Find(m*n+1);      
    }    
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        m = row, n = col;
        par.resize(m*n+2);
        for (int i=0; i<m*n+2; i++)
            par[i] = i;
        
        vector<vector<int>>mat(m, vector<int>(n,1));
        for (auto cell: cells)
            mat[cell[0]-1][cell[1]-1] = 0;
        
        vector<pair<int,int>>dir({{1,0},{-1,0},{0,1},{0,-1}});
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
            {
                if (mat[i][j]==0) continue;
                
                for (int k=0; k<4; k++)
                {
                    int x = i+dir[k].first;
                    int y = j+dir[k].second;
                    if (x<0||x>=m||y<0||y>=n) continue;
                    if (mat[x][y]==0) continue;
                    
                    if (Find(i*n+j)!=Find(x*n+y))
                    {
                        Union(i*n+j, x*n+y);
                    }
                }                
            }
        
        for (int j=0; j<n; j++) Union(m*n, 0*n+j);
        
        for (int j=0; j<n; j++) Union(m*n+1, (m-1)*n+j);
        
        for (int t=cells.size()-1; t>=0; t--)
        {
            if (check()) return t+1;
            
            int i = cells[t][0]-1;
            int j = cells[t][1]-1;
            mat[i][j] = 1;
            
            for (int k=0; k<4; k++)
            {
                int x = i+dir[k].first;
                int y = j+dir[k].second;
                if (x<0||x>=m||y<0||y>=n) continue;
                if (mat[x][y]==0) continue;

                if (Find(i*n+j)!=Find(x*n+y))
                {
                    Union(i*n+j, x*n+y);
                }
            }
        }
        
        return 0;
    }
};