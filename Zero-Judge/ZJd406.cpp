#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int nov[4]={1,0,-1,0};
int mov[4]={0,-1,0,1};//南西北東
bool out(int row,int col,int N,int M){
	if(col>=0&&col<M&&row>=0&&row<N)
		return 0;
	else
		return 1;
}
class Point{
public:
	int row;
	int col;
	int dis;
};
int main()
{
	std::cin.tie(0);
	int s,N,M;//N是橫的 M是直的
	Point ori,next;
	queue<Point> list;
	int x=1;
	while(cin>>s){
		cin>>N>>M;
		int map[N][M],ans[N][M];
		memset(ans,0,4*N*M);//sizeof(ans)
		
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j)
				cin>>map[i][j];//read in map
		}
		
		for(int i=0;i<M;++i){
			if(map[0][i]==1){
				ori.row=0;
				ori.col=i;
				ori.dis=1;
				ans[0][i]=1;
			}
		}//find origin
		list.push(ori);
		while(!list.empty()){
			next=list.front();
			list.pop();
			// cout<<'A'<<endl;             //del
			for(int i=0;i<4;++i){
				if(s==2&&i==2)
					continue;
				int a=next.row+nov[i];
				int b=next.col+mov[i];
				if(!out(a,b,N,M)&&ans[a][b]==0&&map[a][b]==1){
					ori.row=a;
					ori.col=b;
					ori.dis=next.dis+1;
					list.push(ori);
					ans[ori.row][ori.col]=ori.dis;
					// cout<<i<<endl;         //del
				}
			}
		// 	for(int i=0;i<N;++i){
		// 	for(int j=0;j<M;++j)
		// 		cout<<ans[i][j];
		// 	cout<<endl;             //del
		// }
		// cout<<endl;                 //del
		}
		cout<<"Case "<<x<<":"<<endl;
		x++;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}


	return 0;
}