class Solution {
public:
    int uniquePaths(int x, int y, vector<vector<int>>& obstacleGrid, vector<vector<int>>& path_number) {
        if(x>=obstacleGrid.size() || y>=obstacleGrid[0].size()) return 0;
        if(obstacleGrid[x][y] == 1) return 0;
        if(path_number[x][y] != 0) return path_number[x][y];
        
        int number = uniquePaths(x+1, y, obstacleGrid, path_number) +  uniquePaths(x, y+1, obstacleGrid, path_number);
        path_number[x][y] = number;
        cout << "Compute path["<<x<<"][" << y << "] = " << path_number[x][y] << "\n";
        return number;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(row == 1 && col == 1) return 1;
        vector<vector<int>> path_number(row, std::vector<int>(col, 0));
        if(row-1-1 >=0)
            if(obstacleGrid[row-1-1][col-1] != 1)
                path_number[row-1-1][col-1] = 1;
        if(col-1-1 >=0)    
            if(obstacleGrid[row-1][col-1-1] != 1)
                path_number[row-1][col-1-1] = 1;
        uniquePaths(0, 0, obstacleGrid, path_number);
        return path_number[0][0];
    }
};