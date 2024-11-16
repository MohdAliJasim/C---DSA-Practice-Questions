class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans=0;
        vector<int>test;
        for(int i = 0 ; i< points.size();i++){
            test.push_back(points[i][0]);
        }
        sort(test.begin(),test.end());
        for(int i = 0 ; i < test.size()-1;i++){
            if(test[i+1]-test[i]>ans){
                ans = test[i+1]-test[i];
            }
        }
        return ans;
    }
};