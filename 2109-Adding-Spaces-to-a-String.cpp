class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // for(int i =0 ;i < spaces.size();i++){
        //     spaces[i] += i;
        // }
        string str = "";
        int j= 0;
        for(int i= 0 ;i < s.size();i++){
            if(j < spaces.size() && i == spaces[j]){
                str += ' ';
                j++;
            }
            str += s[i];
        }
        // for(int i =0 ;i < spaces.size();i++){
        //     s.insert(s.begin()+spaces[i], ' ');
        // }
        return str;
    }
};