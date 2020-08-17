#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include<queue>
using namespace std;
int main(){
	int scene = 1;//count scenario
	int w,e;
	while(cin>>w>>e){
		if(w==0 && e==0)
			return 0;
		int weight;
		int path[w][w];
		int kg[w];
		bool inqueue[w];
		int From,To;
		map<string,int> hash;
		map<string,int>::iterator it;
		string from,to;
		memset(inqueue,false,sizeof(inqueue));
		for(int i=0;i<w;++i){
			kg[i]=0;
			for(int j=0;j<w;++j)
				path[i][j]=0;
		}
		int num=0;
		for(int i=0;i<e;++i){
			cin>>from>>to>>weight;
			int A,B;
			it = hash.find(from);
			if(it != hash.end())
				A = it->second;
			else{
				A=num;
				hash[from]=num++;
			}
				
			it = hash.find(to);
			if(it !=hash.end())
				B = it->second;
			else{
				B=num;
				hash[to]=num++;
			}
			path[A][B]=path[B][A]=weight;	
		}
		cin>>from>>to;

		// for(int i=0;i<w;++i){
		// 	for(int j=0;j<w;++j)
		// 		cout<<path[i][j]<<" ";
		// 	cout<<endl;
		// }

		it = hash.find(from);
		From = it->second;
		it = hash.find(to);
		To = it->second;
		queue<int>list;
		list.push(From);
		while(!list.empty()){
			int a=list.front();list.pop();
			inqueue[a]=false;
			for(int i=0;i<w;++i){
				if(path[a][i]){
					int max;
					if(kg[a]==0){
						max=path[a][i];
					}
					else{
						if(kg[a]>path[a][i])
							max = path[a][i];
						else
							max = kg[a];
					}
					if(max>kg[i]){
						kg[i]=max;
							if(!inqueue[i]){
								list.push(i);
								inqueue[i]=true;
							}	
					}
				}
			}
			// for(int j=0;j<w;++j)
			// 	cout<<kg[j]<<" ";
			// cout<<endl;
		}
		cout<<"Scenario #"<<scene++<<endl;
		cout<<kg[To]<<" tons"<<endl<<endl;
		}
}