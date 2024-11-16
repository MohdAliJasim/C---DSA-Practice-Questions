class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        for(int i =0 ;i < s.size();i++){
            int mini = INT_MAX;
            for(int j = 0; j < s.size();j++){
                if(s[j]== c){
                    mini = min(mini, abs(j-i));
                }
            }
            ans.push_back(mini);
        }
        return ans;
    }
};