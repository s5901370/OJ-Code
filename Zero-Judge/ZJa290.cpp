#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int city[805][805];
int been[805];
typedef struct ci{
	int from;
	int to;
}City;
int main(){
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(0);
	int N,M,a,b,A,B;//n<800 m<1000000
	vector<ci> stack;
	while(cin>>N){
		cin>>M;
		stack.clear();
		// vector <int> stack;
		City start,move;
		memset(city,0,sizeof(city));
		memset(been,0,sizeof(been));
		for(int i=0;i<M;++i){
			cin>>a>>b;
			city[a][b]=1;//from a to b
		}
		cin>>A>>B;
		for(int i=1;i<=N;++i){
			if(city[A][i]==1&&been[i]==0){//can go and still not have been
				start.from=A;
				start.to=i;
				stack.push_back(start);
				been[i]=1;
				while(!stack.empty()){
					move=stack.back();
					stack.pop_back();
					for(int j=1;j<=N;++j){
						if(city[move.to][j]==1&&been[j]==0){
							start.from=move.to;
							start.to=j;
							stack.push_back(start);
							been[j]=1;
						}	
					}
				}
			}

		}
		if(been[B]==1)
			cout<<"Yes!!!"<<endl;
		else
			cout<<"No!!!"<<endl;
		
	}
	
}
