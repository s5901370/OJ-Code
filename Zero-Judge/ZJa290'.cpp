#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector <int> stack[805];
int been[805];
void DFS(int i){
	for(int j=0;j<stack[i].size();++j){
		if(been[stack[i][j]]==0){
			been[stack[i][j]]=1;
			DFS(stack[i][j]);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N,M,a,b,A,B;//n<800 m<1000000
	while(cin>>N){
		cin>>M;
		for(int i=1;i<=N;++i){
			been[i]=0;
			stack[i].clear();
		}
		for(int i=0;i<M;++i){
			cin>>a>>b;
			stack[a].push_back(b);
		}
		cin>>A>>B;
		for(int i=0;i<stack[A].size();++i){
			if(been[stack[A].at(i)]==0){
				DFS(stack[A].at(i));
				been[stack[A][i]]=1;
			}
		}
		if(been[B]==1)
			cout<<"Yes!!!"<<endl;
		else
			cout<<"No!!!"<<endl;
	}
	
	
}