class Solution {
public:
void dfs(int i, int j, vector<vector<char>>& grid)
{
	int n = grid.size();
	int m = grid[0].size();
	if(i<0||j<0) return;
	if(i>=n||j>=m) return;
	if(grid[i][j]!='1') return; //visited array is not needed as if we go to same node after changing, this line is executed and dfs() is not called
	grid[i][j] = '2';  // Mark '2' as visited.
	dfs(i-1, j, grid);
	dfs(i+1, j, grid);
	dfs(i, j-1, grid);
	dfs(i, j+1, grid);
	
}
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == '1') {
          dfs(i,j,grid);
          ++ans;
        }
        return ans;
    }
};