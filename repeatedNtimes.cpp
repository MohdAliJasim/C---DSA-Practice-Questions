#include<iostream>
using namespace std;

int main(){
    int n; cin >> n;
    string str; cin >> str;
    string newStr = "";
    while(n--){
        newStr.append(str);
    }
    cout << newStr;
    return 0;
}