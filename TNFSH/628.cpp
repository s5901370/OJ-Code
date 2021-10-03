#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//sort(v.begin(),v.end())
// ios::sync_with_stdio(false);
// cin.tie(0);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N,M,K;
	cin>>N>>M>>K;// N studens, M schools, K people allowed per school
	int order[N+1];
	vector<int> choose[M+1];
	int wish[N+1][6];
	int MAX[M+1]={0};
	for (int i = 1; i <= N; ++i)
	{
		cin>>order[i];
		/* code */
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			cin>>wish[i][j];
		}
	}
	// printf("AAA\n");

	for(int i=1;i<=N;++i){
		int s = order[i];
		bool flag = true;
		int j=1;
		while(flag && j<=5){
			// if(s == 239)
			// printf("s=%d j=%d\n",s,j);
			int sch = wish[s][j];
			if(MAX[sch] < K){
				MAX[sch]++;
				flag = false;
				choose[sch].push_back(s);
			}
			else{
				++j;
			}
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		int size = choose[i].size();
		if(size > 0){
			sort(choose[i].begin(),choose[i].end());
			cout<<size;
			for(int j=0;j<size;++j){
				cout<<" "<<choose[i].at(j);
			}
			cout<<endl;
		}
		else
			cout<<0<<endl;
	}

}