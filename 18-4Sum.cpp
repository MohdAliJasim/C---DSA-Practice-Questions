class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        if(nums.size() < 4 ){
            return res;
        }
        
        int n = nums.size();

        if(nums[0] == nums[n-1]){
              long long ini = nums[0] + nums[1];
                        if(ini > INT_MAX) return res;
                        ini += nums[2];
                        if(ini > INT_MAX) return res;
                        ini += nums[3];
                        if(ini > INT_MAX) return res;
                        if( ini == target){
                            res.push_back({nums[0], nums[0], nums[0],nums[0]});   
                        }
                         return res;
        }
        for(int a = 0 ;a < n-3; a++){
            for(int b = a+1; b< n-2;b++){
                for(int c = b+1 ; c < n -1; c++){
                    for(int d = c+1;d < n;d++){
                      
                        long long ini = nums[a] + nums[b];
                        if(ini > INT_MAX) continue;
                        ini += nums[c];
                        if(ini > INT_MAX) continue;
                        ini += nums[d];
                        if(ini > INT_MAX) continue;
                        if( ini == target){
                      
                         
                            ans.insert({nums[a], nums[b], nums[c],nums[d]});
                         
                        }
                    }
                }
            }
        }
        
        for(auto v : ans){
            res.push_back(v);
        }
        return res;
    }
};