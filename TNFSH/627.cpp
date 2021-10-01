#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//sort(v.begin(),v.end())
// ios::sync_with_stdio(false);
// cin.tie(0);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin>>N;
	long long int height[N+1];
	for (int i = 1; i <= N; ++i)
	{
		cin>>height[i];
	}
	long long int Q;
	cin>>Q;
	int X,Y;
	for (int i = 0; i < Q; ++i)
	{
		cin>>X>>Y;
		cout<<height[(X+Y)/2]<<endl;		
	}
	
}