#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool f(int arr[] , vector<int> &ds, int n , int index , int k , int sum){
  if(index == n){
    if(sum == k){
      for(auto a: ds) cout << a << " ";
      cout << endl;
      return true;
    }
    return false;
  }
  ds.push_back(arr[index]);
  sum += arr[index];
  if(f(arr , ds , n , index+1 , k , sum)) return true;
  ds.pop_back();
  sum -= arr[index];
  
  if(f(arr, ds , n , index+1 , k , sum)) return true;
  
  return false; 
}

int main(){
  int arr [] = {1,2,1};
  vector<int>ds;
  f(arr , ds , 3, 0, 3,0);
}