class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        unordered_map<int,int> map;
        for(int it : arr2) map[it]++;

        for(int i = 0;i < arr1.size();i++){
            if(map[arr1[i]]){
                map[arr1[i]]++;
            }
        }

        
        for(int i = 0;i < arr2.size();i++){
            for(int j = 1; j < map[arr2[i]]; j++){
                ans.push_back(arr2[i]);
            }
        }
        vector<int> remaining ;
        for(int i = 0;i < arr1.size();i++){
            if(map[arr1[i]]) continue;
            remaining.push_back(arr1[i]);
        }
        sort(remaining.begin(),remaining.end());

        for(int i=0 ;i < remaining.size();i++){
            ans.push_back(remaining[i]);
        }
        return ans;
    }
};