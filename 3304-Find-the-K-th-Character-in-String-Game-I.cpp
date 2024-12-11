class Solution {
public:
    char kthCharacter(int k) {
        if(k == 1) return 'a';
        string str = "a";
        while(str.size() < k){
            string s = "";

            for(int i = 0; i < str.size();i++){
                s += str[i] +1;
            }
            str += s;
        }
        return str[k-1];
    }
};