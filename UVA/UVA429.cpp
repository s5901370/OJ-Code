#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N;
	cin>>N;
	// char c[3];
	// gets(c);
	string c;
	getline(cin,c);
	for(int w=0;w<N;++w){
		vector<string> v;
		vector<string> an,ans;
		string s;
		while(cin>>s){
			if(s=="*"){
				string temp;
				// cout<<"B";
				// char c;
				// cin>>
				// cout<<"C";
				
				getline(cin,temp);
				while(getline(cin,temp)){
					// cout<<"A";
					if(temp=="")
						break;
					an.push_back(temp);
				}
				for(int z=0;z<an.size();++z){
					int d=0;
					while(an[z][d]!=' ')d++;
					ans.push_back(an[z].substr(0,d));
					ans.push_back(an[z].substr(d+1,an[z].size()-1-d));
				}
				break;
			}
			v.push_back(s);
		}
		//create graph
		int size = v.size();
		int path[size][size];
		for(int i=0;i<size;++i){
			for(int j=i;j<size;++j){
				int diff=0;
				if(v[i].size()==v[j].size()){
					for(int k=0;k<v[i].size();++k)
						if(v[i][k]!=v[j][k])
							diff++;
					if(diff==0)
						path[i][j]=path[j][i]=0;
					else if(diff==1)
						path[i][j]=path[j][i]=1;
					else
						path[i][j]=path[j][i]=200;
				}
				else
					path[i][j]=path[j][i]=200;
			}
		}
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				for(int k=0;k<size;k++)
					if(path[j][k]>path[j][i]+path[i][k])
						path[j][k]=path[j][i]+path[i][k];
					////

		// 			cout<<"    ";
		// for(int i=0;i<size;++i)cout<<v[i]<<" ";
		// 	cout<<endl;
		// for(int i=0;i<size;++i){cout<<v[i]<<"  ";
		// 	for(int j=0;j<size;++j){
		// 		cout<<setw(3)<<path[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		//
		for(int q=0;q<ans.size()/2;++q){
			string from = ans[2*q],to = ans[2*q+1];
			int go,went;
			for(int i=0;i<size;++i)
				if(from == v[i])
					go=i;
			for(int i=0;i<size;++i)
				if(to == v[i])
					went=i;
			cout<<from<<" "<<to<<" "<<path[go][went]<<endl;
		}
		if(w!=N-1)
			cout<<endl;
	}
}