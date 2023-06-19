#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// if the target is not in array
// find the element greater than the target
int bs_right(int low,vector<int> &arr){
     int l=0,r=arr.size()-1;
     while(l<r){
          cout<<"l="<<arr[l]<<",r="<<arr[r]<<endl;
          int mid = (l+r)/2; // here is the diff
          if(arr[mid]>=low){
               r = mid;
          }
          else{
               l = mid +1 ;
          }

     }
     cout<<"l="<<arr[l]<<",r="<<arr[r]<<endl;
     return l;
}
// if the target is not in array
// find the element smaller than the target
int bs_left(int low,vector<int> &arr){
     int l=0,r=arr.size()-1;
     while(l<r){
          cout<<"l="<<arr[l]<<",r="<<arr[r]<<endl;
          int mid = (l+r+1)/2;  // here is the diff
          if(arr[mid]>=low){
               r = mid - 1;
          }
          else{
               l = mid ;
          }

     }
     cout<<"l="<<arr[l]<<",r="<<arr[r]<<endl;
     return l;
}
int main() {         //0,1,2,3,4,5,6,7
    vector<int> arr = {1,2,3,4,6,7,8,9};
    cout<<bs_left(5,arr)<<endl;
    cout<<bs_right(5,arr)<<endl;
    return 0;
}
