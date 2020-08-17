#include <iostream>
#include <cstring>
using namespace std;
int top=0;
int a[5005];
int pop(){
	int i=2;
	int ans = a[1];
	a[1]=a[top];
	top--;
	while(i<=top){
		if(a[i]<a[i+1]){
			if(a[i/2]>a[i]){
				int t=a[i/2];
				a[i/2]=a[i];
				a[i]=t;
				i=2*i;
			}
			else
				break;
		}
		else{
			if(a[i/2]>a[i+1]){
				int t=a[i/2];
				a[i/2]=a[i+1];
				a[i+1]=t;
				i=(i+1)*2;
			}
			else
				break;
		}
	}
	// cout<<ans<<" ";
	return ans;
}
void swap(int i){//越小越上面
	// if((top/2)>=1){
	while((i/2)>=1){
		if(a[i/2]>a[i]){
			int temp=a[i/2];
			a[i/2]=a[i];
			a[i]=temp;
			i/=2;
		}
		else
			return;
	}
	
}
int main(){
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(0);
	long long int ans;
	// int cost[5005];
	int N;
	int n;
	while(cin>>N){
		if(N==0)
			return 0;
		memset(a,0,sizeof(a));
		top=0;
		ans=0;
		for(int i=0;i<N;++i){
			top++;
			cin>>n;
			a[top]=n;
			swap(top);
		}
		// for(int i=1;i<=N;++i)
		// 	cout<<a[i]<<" ";
		// cout<<endl;
		
		int cost[5005];
		int j=0;
		
		for(int i=0;i<(N-1);++i){
			cost[j]=pop()+pop();
			top++;
			a[top]=cost[j++];
			swap(top);
		}
		
		// cout<<endl;
		// for(int i=0;i<N-1;++i)
		// 	cout<<cost[i]<<" ";
		// cout<<endl;
		for(int i=0;i<N-1;++i)
			ans+=cost[i];
		cout<<ans<<endl;
	}
}