#include <iostream>
#include <string>
 using namespace std;

int main(){
    
    string str; getline(cin ,str);
    string newStr = "";
    int n; cin >> n;
    int i = 0;
    while(n){
        if(str[i] == ' '){
            n--;
            if(!n)
                break;
        }
        newStr += str[i];
        i++;
    }
    cout << newStr;
    return 0;
}


















