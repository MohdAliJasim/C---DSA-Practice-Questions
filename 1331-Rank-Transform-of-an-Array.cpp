class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int,int> map;        
        set<int> st(arr.begin(), arr.end());
        vector<int> rank(st.begin(),st.end());
        sort(rank.begin(),rank.end());
        for(int i =0 ;i< rank.size();i++){
            map[rank[i]] = i+1;
        }
        for(int a : arr) ans.push_back(map[a]);
   
        return ans;
    }
};