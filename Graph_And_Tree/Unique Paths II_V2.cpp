class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> path(row+1, vector<int>(col+1, 0));
        path[1][0] = 1;
        for(int i=1; i<=row; ++i)
            for(int j=1; j<=col; ++j)
            {
                if(obstacleGrid[i-1][j-1] != 1)
                    path[i][j] = path[i-1][j] + path[i][j-1];
            }
        return path[row][col];
    }
};