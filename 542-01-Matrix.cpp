class Solution {
public:
    int r , c;
    vector<int> dx = {0,0,-1,1};
    vector<int> dy = {-1,1,0,0};

    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        r = mat.size();
        c = mat[0].size();

        vector<vector<bool>> visited(r , vector<bool>(c, false));

        queue<pair<int,int>>q;

        for(int i = 0 ;i < r;i++){
            for(int j = 0 ;j < c; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }


        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            while(size--){
                pair<int,int>p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for(int k = 0 ; k < 4;k++){
                    int i = x + dx[k];
                    int j = y + dy[k];
                    if(i<0 or j<0 or i>=r or j>=c or visited[i][j]) continue;

                     mat[i][j] = count;
                     visited[i][j]= true;
                     q.push({i,j});   

                }
            }
        }
        return mat;
    }
};