#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int stick[20];
bool used[20];
int l;
int n;
int _time;
bool my(int i,int j){return i>j;}
bool DFS(int len,int num){
	if( _time == 3)
			return true;
	// if(len == 0){
	// 	int k=0;
	// 	while(used[k])k++;// go to unused
	// 	if(DFS(stick[k],k+1,_time))return true;
	// }
	if(len == l){ // stop
		// cout<<_time<<endl;
		_time++;
		if(DFS(0,0))
			return true;
		_time--;
	}
	for(int i=num;i<n;++i){
		if(!used[i] && len+stick[i] <= l){
			if(!used[i-1] && stick[i] == stick[i-1])continue;  // the most important
			used[i]=true;
			if(DFS(len+stick[i],i+1)) return true;
			used[i]=false;
		}
	}
	return false;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N;
	cin>>N;
	for(int f=0;f<N;++f){
		cin>>n;
		// cout<<f<<endl;  			//
		l=0;
		_time = 0;
		memset(used,false,sizeof(used));
		for(int i=0;i<n;++i){
			cin>>stick[i];
			l+=stick[i];
		}
		sort(stick,stick+n,my);//sorted from big to small
		if(l%4!=0){
			cout<<"no"<<'\n';
			continue;
		}
		else{
			l/=4;
			// if(stick[0]>l){
			// 	cout<<"no"<<endl;
			// 	continue;
			// }
			if(DFS(0,0))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
		}
		
			
	}
}