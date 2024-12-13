class Solution {
public:
    long long findScore(vector<int>& nums) {
        unordered_map<int, vector<int>> map;
        long long ans = 0;
        vector<bool>marked(nums.size(), false);
       

        for(int i =0 ;i < nums.size();i++){
            map[nums[i]].push_back(i);
        }

        // for(auto a : map){
        //     cout << a.first;
        //     for(int num : a.second){
        //         cout << num << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        int count = 0;
        for(int i =0 ;i < temp.size();i++){
            int num = temp[i];

            vector<int>arr (map[num].begin(),map[num].end());
            
            for(int j = 0; j < arr.size();j++){
                    if(!marked[arr[j]]){
                        ans += num;
                        marked[arr[j]] = true;
                        count++;
                        if(arr[j] > 0){
                            marked[arr[j]-1] = true;
                            count++;
                        } 
                        if(arr[j] < nums.size()-1){
                            marked[arr[j]+1] = true;
                            count++;
                        } 

                    }
            }
            if(arr.size() == nums.size()){
                return ans;
            } 

        }
        return ans;
    }
};