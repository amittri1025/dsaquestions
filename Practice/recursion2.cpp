#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int> arr, int n, int i){
  
  if(i==n) return ;
  reverse(arr, n,  i+1);
  cout<<arr[i]<<" ";
}

int main(){
  
  vector<int> arr{1,2,3,4,5};
  int n= arr.size();
  reverse(arr, n, 0);

}