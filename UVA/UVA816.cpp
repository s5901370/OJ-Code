#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Point
{
	int M;
	int N;
	char d;//where it come from
};
int main(){
	vector<string> dir[10][10];//direction
	string name;
	int oriM,oriN,desM,desN;
	char des,oriD;
	string X;
	while(cin>>name){
		for(int i=1;i<10;++i)
			for(int j=1;j<10;++j)
				dir[i][j].clear();
		if(name == "END")
			return 0;
		cin>>oriM>>oriN>>oriD>>desM>>desN;
		int a,b;
		while(cin>>a){
			if(a==0)
				break;
			cin>>b;
			while(cin>>X){
				if(X=="*")
					break;
				dir[a][b].push_back(X);
			}
		}

		// for(int i=1;i<10;++i){
		// 	for(int j=1;j<10;++j){
		// 		for(int k=0;k<dir[i][j].size();++k)
		// 			cout<<dir[i][j][k]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		int pre[10][10][4]={0};//m*9+n is it's predecessor 0=E 1=S 2=W 4=N
		queue<Point> list;
		Point ori,next;
		switch(oriD){
			case 'E'://from left
				ori.M=oriM;ori.N=1+oriN;ori.d = oriD;
				break;
			case 'S'://from top
				ori.M=oriM+1;ori.N=oriN;ori.d = oriD;
				break;	
			case 'W'://from right
				ori.M=oriM;ori.N=oriN-1;ori.d = oriD;
				break;	
			case 'N'://from down
				ori.M=oriM-1;ori.N=oriN;ori.d = oriD;
				break;	
		}
		int qwe;
		if(ori.d == 'E')
			qwe = 0;
		else if(ori.d == 'S')
			qwe = 1;
		else if(ori.d == 'W')
			qwe = 2;
		else 
			qwe = 3;
		pre[ori.M][ori.N][qwe] = oriM*100+oriN*10+5;
		list.push(ori);
		while(!list.empty()){
			ori = list.front();
			int M = ori.M,N = ori.N;
			if(M == desM && N == desN){//stop
				des = ori.d;
				break;
			}
			char D = ori.d;
			list.pop();

			// cout<<ori.M<<" "<<ori.N<<endl;//
			// cout<<ori.d<<endl;

			for(int i=0;i<dir[M][N].size();++i){
				if(D == dir[M][N][i][0]){


					for(int j=1;j<dir[M][N][i].size();++j){
						char C = dir[M][N][i][j];

						// cout<<"C"<<endl;				/////

						switch(D){
							case 'E'://from left
								switch(C){
									case 'L':
										next.M = M-1;next.N = N;next.d = 'N';
										break;
									case 'R':
										next.M = M+1;next.N = N;next.d = 'S';
										break;
									case 'F':
										next.M = M;next.N = 1+N;next.d = 'E';
										break;
								}
								break;
							case 'S'://from top
								switch(C){
									case 'L':
										next.M = M;next.N = 1+N;next.d = 'E';
										break;
									case 'R':
										next.M = M;next.N = N-1;next.d = 'W';
										break;
									case 'F':
										next.M = M+1;next.N= N;next.d = 'S';
										break;
								}
								break;	
							case 'W'://from right
								switch(C){
									case 'L':
										next.M = M+1;next.N = N;next.d = 'S';
										break;
									case 'R':
										next.M = M-1;next.N = N;next.d = 'N';
										break;
									case 'F':
										next.M = M;next.N = N-1;next.d = 'W';
										break;
								}
								break;	
							case 'N'://from down
								switch(C){
									case 'L':
										next.M = M;next.N = N-1;next.d = 'W';
										break;
									case 'R':
										next.M = M;next.N = N+1;next.d = 'E';
										break;
									case 'F':
										next.M = M-1;next.N = N;next.d = 'N';
										break;
								}
								break;	
						}
						int asd;
						if(next.d == 'E')
							asd = 0;
						else if(next.d == 'S')
							asd = 1;
						else if(next.d == 'W')
							asd = 2;
						else 
							asd = 3;

						// cout<<asd<<endl;			///////

						if(pre[next.M][next.N][asd]==0){

							// cout<<"D"<<endl;
							int sss;
							if(ori.d == 'E')
								sss = 0;
							else if(ori.d == 'S')
								sss = 1;
							else if(ori.d == 'W')
								sss = 2;
							else 
								sss = 3;
							list.push(next);
							pre[next.M][next.N][asd] = M*100+N*10+sss;
							// cout<<pre[next.M][next.N][asd]<<" ";
						}
					}//inside for

					break;
				}//if
			}//for loop
		}//while loop
		cout<<name<<endl;
		int asd;
		if(des == 'E')
			asd = 0;
		else if(des == 'S')
			asd = 1;
		else if(des == 'W')
			asd = 2;
		else 
			asd = 3;
		// cout<<asd;
		if(pre[desM][desN][asd]!=0){
			// cout<<"  "<<"a"<<endl;
			a = desM;b = desN;
			vector<int> v[2];
			v[0].push_back(a);v[1].push_back(b);
			bool f = true;
			while(a!=oriM || b!= oriN || asd!=5 || f){//using a b as m n
				int y = pre[a][b][asd];
				f= false;
				// cout<<y<<" ";//

				a = y/100;y%=100;
				b = y/10;y%=10;
				asd = y;
				// cout<<a<<" "<<b<<endl;
				v[0].push_back(a);v[1].push_back(b);

			}
			cout<<" ";
			int count = 0;
			for(int i=v[0].size()-1;i>=0;--i){
				if(count == 10){
					count=0;
					cout<<endl<<" ";
				}
				cout<<" ("<<v[0][i]<<","<<v[1][i]<<")";
				
				count++;
			}
			cout<<endl;
		}
		else
			cout<<"  "<<"No Solution Possible"<<endl;
		
	}
}