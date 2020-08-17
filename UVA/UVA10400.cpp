#include<iostream>
#define MAX 32000
#define MIN -32000
#include<cstring>
using namespace std;
bool nice;
int n;
int num[105];
int target;
char op[105];
bool used[101][64004];

void DFS(int count,int sum){
	if(nice)
		return;
	if(sum>MAX || sum<MIN)
		return;
	if(used[count][sum+32000] == true)
		return;
	used[count][sum+32000] = true;
	if(count == n-1){
		if(sum == num[n])
			nice = true;
		return;
	}
	op[count]='+';
	DFS(count+1,sum+num[count+1]);
	if(nice) return;

	op[count]='-';
	DFS(count+1,sum-num[count+1]);
	if(nice) return;

	op[count]='*';
	DFS(count+1,sum*num[count+1]);
	if(nice) return;

	if(sum%num[count+1]==0){
		op[count]='/';
		DFS(count+1,sum/num[count+1]);
		if(nice) return;
	}
}

int main(){
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>n;//num[n] is answer
		for(int k=0;k<=n;++k)
			cin>>num[k];
		memset(used,false,sizeof(used));
		nice = false;
		DFS(0,num[0]);

		if(nice){
			for(int j=0;j<n-1;++j)
				cout<<num[j]<<op[j];
			cout<<num[n-1]<<'='<<num[n]<<'\n';
		}
		else{
			cout<<"NO EXPRESSION"<<'\n';
		}
	}
}