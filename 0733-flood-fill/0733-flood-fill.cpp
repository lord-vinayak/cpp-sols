class Solution {
public:
void dfs(int i, int j, int inital, int newcolor, vector<vector<int>>& image)
{
	int n = image.size();
	int m = image[0].size();
	if(i<0||j<0) return;
	if(i>=n||j>=m) return;
	if(image[i][j]!=inital) return; //visited array is not needed as if we go to same node after changing, this line is executed and dfs() is not called

	image[i][j]=newcolor;

	dfs(i-1, j, inital, newcolor, image);
	dfs(i+1, j, inital, newcolor, image);
	dfs(i, j-1, inital, newcolor, image);
	dfs(i, j+1, inital, newcolor, image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{
	int inital = image[sr][sc];
	if(inital!=color)
    dfs(sr, sc, inital, color, image); 
    return image;   
}
};