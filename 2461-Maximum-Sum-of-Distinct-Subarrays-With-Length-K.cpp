class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int r= 0;
        int l = 0;
        long long sum = 0;
        for(int i = 0; i < k ;i++){
            map[nums[i]]++;
            sum += nums[i];
        }
        long long maxi = 0;
        r = k-1;
        while(r < nums.size()){
            if(map.size()==k){
                maxi = max(maxi,sum);
            }
            sum -= nums[l];
            map[nums[l]]--;
            if(map[nums[l]] == 0) map.erase(nums[l]);
            l++;
            r++;
            if(r < nums.size()){
              sum += nums[r];
              map[nums[r]]++;  
            } 
        }
    return maxi;
    }
};