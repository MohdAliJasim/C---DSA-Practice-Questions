class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> para;
        for(string s : strs){
            string m = s;
            sort(m.begin(),m.end());
            para[m].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto a : para){
            ans.push_back(a.second);
        }
        return ans;
    }
};