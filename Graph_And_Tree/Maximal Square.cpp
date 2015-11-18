class Solution {
	// The intersection of three squares.
public:

	int SquareSize(int x, int y, vector<vector<char>>& matrix, vector<vector<int>>& maxsize) {
		if(x < 0 || y < 0 ) return 0;
		if(matrix[x][y] == 0) {maxsize[x][y] = 0; return 0;}
		if(maxsize[x][y] != -1) return maxsize[x][y]; 
		else{
			int val = min(SquareSize(x-1, y-1, matrix, maxsize), min(SquareSize(x-1, y, matrix, maxsize), SquareSize(x, y-1, matrix, maxsize)))+1; 
			maxsize[x][y] = val;
			return val;
		}
	}

    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> maxsize(row, vector<int>(col, -1));
        int max = INT_MIN;
        for (int i = 0; i < row; ++i)
        {
        	for (int j=0; j<col; ++j) {
        		int val = SquareSize(i, j, matrix, maxsize);
        		if (val > max) val = max;
        	}
        }
        return max;
    }
};	
