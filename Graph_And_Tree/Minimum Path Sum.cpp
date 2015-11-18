class Solution {
public:

    int minSum(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& min) {
    	if(x == 1 && y == 1) return grid[0][0];
    	if(min[x][y]<INT_MAX) return min[x][y];
    	int up = minSum(x, y-1, grid, min);
    	int left  =  minSum(x-1, y, grid, min);
    	int min_path = up < left?up:left;
    	min_path += grid[x-1][y-1];
    	min[x-1][y-1] = min_path;
    	return min_path;
    }

    int minPathSum(vector<vector<int>>& grid) {
    	int row= grid.size();
    	int col = grid[0].size();
        vector<vector<int>> minvec(row+1, vector<int>(col+1, INT_MAX));
        return minSum(row, col, grid, minvec);
    }
};