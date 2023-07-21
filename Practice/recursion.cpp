#include <iostream>
#include <vector>
using namespace std;

// sum of first n numbers
// 1, 2, 3, 4, 5,....N
// when n = 10 stop

//Parameterized Recursion

// int sumofn(int i, int sum){
//   if(i==0){
//     return sum;
//   }
//   sumofn(i-1, sum+i); 
// }

// int fact(int n,int ans){
//   if(n==0) return ans;
//   fact(n-1, ans*n);
// }

// Functional Recursion

// int sumofn(int n){
//   if(n==0) return 0;
//   return n + sumofn(n-1);
// }

// int fact(int n){
//   if(n==0) return 1;
//   return n * fact(n-1);
// }

// reversing an array
// void reverse(vector<int> &arr, int i, int n){
//   if(i>=n/2){
//     return;
//   }
//   swap(arr[i], arr[n-i-1]);
//   reverse(arr, i+1 ,n-1);
// }

// bool checkPalindrome(int i, string str, int n){
//   if(i>=n/2){
//     return true;
//   }
//   if(str[i]!=str[n-i]){
//      return false;
//   }else{
//     return checkPalindrome(i+1, str, n);
//   }
// }
//  find  Fibonnanci till N number
//  n = 10, so 0 1 1 2 3 5 8 13 21 

int fibo(int n){
  if(n<=1){
    return n;
  }
  return fibo(n-1) + fibo(n-2);
}

void subsequence(int ind, vector<int> &ds, int arr[], int n){
  if(ind == n){
      for(auto i: ds)
        cout<< i << " ";
      
      if(ds.size() == 0)
        cout<< "{}";
        
      cout<<endl;
      return;
  }

  ds.push_back(arr[ind]);
  subsequence(ind + 1, ds, arr, n);
  ds.pop_back();

  subsequence(ind+1, ds, arr, n);
}

void subsSum(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
  if(ind==n){
    if(s==n){
      for(auto it: ds) cout<<it << " ";
      cout<<endl;
    }
    return;
  }
  ds.push_back(arr[ind]);
  s+=arr[ind];
  ds.pop_back();

  // not pick
  subsSum(ind+1, ds, s, sum, arr, n);
}

int main(){
// print all the subsequences 
  int arr[] = {1,2,3};
  int n = 3;
  int sum = 2;
  vector<int> ds;
  subsSum(0, ds, 0, sum, arr, n);
 
  return 0;
}

