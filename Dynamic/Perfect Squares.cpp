class Solution {
public:

    int numSquares(int n, vector<int>& res){
        if(n == 0) return 0;
        if(res[n] != -1) return res[n];
        int max_squ = sqrt(n);
        if(max_squ*max_squ == n) {
            res[n] = 1;
            return 1;
        }
        int least = INT_MAX;
        for(int i=1; i<=max_squ; ++i) {
            int val = 1 + numSquares(n-i*i, res);
            if(val < least) least = val;
        }
        res[n] = least;
        return least;
    }
    
    int numSquares(int n) {
        vector<int> res(n+1, -1);
        return numSquares(n, res);
    }
};
