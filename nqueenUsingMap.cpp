class Solution{
public:
	void f(int col,int n , vector<vector<int>> &ans, vector<vector<int>> & board , vector<int> & prevRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal){
	if(col == n){
		vector<int> ds;
		for(auto a : board){
			for(auto b: a){
				ds.push_back(b);
			}
		}
	}

	for(int row = 0; row < n;row++){
		if(prevRow[row] == 0 && upperDiagonal[n-1+col-row] == 0 && lowerDiagonal[row+col] == 0){
			prevRow[row] = 1;
			upperDiagonal[n-1+col-row] = 1;
			lowerDiagonal[row+col] = 1;
			board[row][col] = 1;
			f(col+1, n , ans , board, preRow ,upperDiagonal, lowerDiagonal);
			preRow[row] = 0;
			upperDiagonal[n-1+col-row] = 0;
			lowerDiagonal[row+col]= 1;
			board[row][col] = 0;
		}
	}
}
    vector<vector<int>> nQueen(int n) {
    	vector<vector<int>> ans;
	vector<vector<int>> board(n , vector<int> (n, 0));
	vector<int>prevRow(n,0);
	vector<int>upperDiagonal(n*2-1,0);
	vector<int>lowerDiagonal(n*2-1,0);
	f(0,n , ans , board , prevRow, upperDiagonal, lowerDiagonal);	
	return ans;	
    }
};
