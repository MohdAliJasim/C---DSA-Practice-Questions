#include <iostream>
#include <queue>

using namespace std;

int main(){
  string str; cin >> str;
  int k ; cin >> k;
  int n = str.size();
  queue<int> q;
  int cnt= 0;
  int aCnt = 0;
  for(int i = 0; i < k;i++){
    if(str[i] == 'a')
      aCnt++;
    q.push(str[i]);
  }
  if(aCnt)
    cnt++;
  for(int i = k ; i < n ; i++){
    char ch = q.front();
    if(ch == 'a')
      aCnt--;
    q.pop();
    if(str[i] == 'a')
      aCnt++;
    q.push(str[i]);
    if(aCnt)
      cnt++;
  }
  cout << cnt;
  return 0;
}