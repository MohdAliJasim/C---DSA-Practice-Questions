class Solution {
public:
    string addBinary(string a, string b) {
        string res = \\;

       

        int carry = 0;

        int i = a.size()-1;
        int j = b.size()-1;

        while(i >= 0 || j >= 0){
            if(i >= 0 && j  >= 0){
                int ans =  (a[i] - '0') + (b[j] - '0') + carry;
                carry = 0;
                if(ans == 1) res += '1';
                else if(ans == 0) res += '0';
                else if(ans == 2){
                    res+='0';
                    carry = 1;
                }
                else{
                    res+= '1';
                    carry=1;
                }
                i--;
                j--;
            }
            else if( i  >= 0){
                int ans = a[i] - '0' + carry;
                carry =0;
                 if(ans == 0){
                    res += '0';
                }
                else if(ans == 1){
                    res += '1';
                    
                }
                else{
                    res += '0';
                    carry = 1;
                }
                i--;
            }
            else{
                int ans = b[j] - '0' + carry;
               
                carry = 0;
               if(ans == 0){
                    res += '0';
                }
                else if(ans == 1){
                    res += '1';
                    
                }
                else{
                    res += '0';
                    carry = 1;
                }
                j--;
            }
        }
        if(carry) res += '1';
        reverse(res.begin(),res.end());
        int count = 0;
        while(res[count] == 0){
            count++;
        }
        if(count == res.size()) return \0\;
        return res.substr(count);
    }
};