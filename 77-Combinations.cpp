class Solution {
public:

    void solve(vector<int> & arr, int k , int i , vector<int> &temp , set<vector<int>>&ans){
      
           if(temp.size() == k){
            ans.insert(temp);
            return;
           }
    

        for(int j = i; j < arr.size();j++){
           
                temp.push_back(arr[j]);
               solve(arr,k , j+1,temp,ans);
                temp.pop_back();
            
            
        }
    }

    vector<vector<int>> combine(int n, int k) {
        set<vector<int>> ans;
        vector<int> temp;
        vector<int> arr;
        for(int i = 1;i <= n;i++){
            arr.push_back(i);
        }
        solve(arr , k , 0, temp, ans);
        vector<vector<int>> res;
        for(auto s : ans) res.push_back(s);
        return res;
    }
};