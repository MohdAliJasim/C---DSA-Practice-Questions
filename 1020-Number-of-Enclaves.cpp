class Solution {
public:
    int r , c;
    vector<int> dx= {0,0,-1,1};
    vector<int> dy  = {-1,1,0,0};

    void dfs(vector<vector<int>>& grid , vector<vector<bool>>& visited , int x ,int y ){
        if(x<0 or y < 0 or x >= r or y >= c or visited[x][y] or grid[x][y] == 0) return;
        visited[x][y] = true;

        for(int k = 0; k < 4;k++){
            int i = x + dx[k];
            int j = y + dy[k];
            dfs(grid, visited, i,j);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        vector<vector<bool>> visited(r , vector<bool>(c, false));

        for(int i = 0;i < r ;i++){
            for(int j = 0;j < c;j++){
                if(grid[i][j] == 0) visited[i][j] = true;
                if(i == 0 or j == 0 or i == r-1 or j== c-1){
                    if(!visited[i][j] && grid[i][j] == 1 ){
                        dfs(grid, visited, i,j);
                    }
                }
            }
        }    
        int count = 0;
        for(int i =0 ;i < r;i++){
            for(int j =0 ;j < c ;j++){
                if(!visited[i][j]) count++;
            }
        }
        return count;
    }
};