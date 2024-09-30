
bool isSafe(int row , int col , vector<vector<int>>&ds, int n){
    int dubRow;
    int dubCol = col-1;
    while(dubCol >= 0){
        if(ds[row][dubCol] == 1) return false;
        dubCol--;
    }
    dubRow = row-1;
    dubCol = col-1;
    while(dubCol >= 0 && dubRow >= 0){
        if(ds[dubRow][dubCol] == 1) return false;
        dubCol--;
        dubRow--;
    }
    dubRow = row+1;
    dubCol = col-1;
    while(dubCol >= 0 && dubRow < n){
        if(ds[dubRow][dubCol] == 1) return false;
        dubRow++;
        dubCol--;
    }
    return true;
}

void fQ(int col, int n , vector<vector<int>>& ans, vector<vector<int>>& ds){
    if(col == n){
        vector<int> newAns;
        for(auto a : ds){
            for(auto b: a){
                newAns.push_back(b);
            }
        }
        ans.push_back(newAns);
    }

    for(int row = 0 ; row < n; row++){
        if(isSafe(row , col , ds , n)){
            ds[row][col] = 1;
            fQ(col+1,n, ans , ds);
            ds[row][col] = 0;
        }
        
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> ds;
    for(int i =0 ; i< n ;i++){
        vector<int> temp;
        for (int j =0  ; j < n;j++){
            temp.push_back(0);
        }
        ds.push_back(temp);
    }
    fQ(0,n,ans,ds);
    return ans;
}