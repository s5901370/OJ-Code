#include<bits/stdc++.h>
using namespace std;
int lower_true(vector<bool> &arr){
    int l = 0, r = arr.size()-1;
    while(l < r){
        int mid = (r-l)/2 + l;
        printf("l=%d mid=%d r=%d\n",l,mid,r);
        if(arr[mid]){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return r;
    // return l;
}
int upper_true(vector<bool> &arr){
    int l = 0, r = arr.size()-1;
    while(l < r){
        int mid = (r-l+1)/2 + l;
        printf("l=%d mid=%d r=%d\n",l,mid,r);
        if(arr[mid]){
            l = mid;
        }
        else{
            r = mid-1;
        }
    }
    // return l;
    return r;

}
int main(int argc, char const *argv[])
{                       //0  1    2    3    4    5    6     7      8   
    vector<bool> low = {true,true,true,true,true,false,false,false,false};
                       //0     1    2      3    4    5    6     7   8   
    vector<bool> high = {false,false,false,false,true,true,true,true,true};
    cout<<lower_true(low)<<endl;
    cout<<lower_true(high)<<endl;
    cout<<upper_true(low)<<endl;
    cout<<upper_true(high)<<endl;
}
