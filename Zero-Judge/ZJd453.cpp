#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int nov[4]={1,0,-1,0};
int mov[4]={0,-1,0,1};//南西北東
bool out(int row,int col,int N,int M){
	if(col>0&&col<=M&&row>0&&row<=N)
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
void clear(queue<Point> &q){
	queue<Point> empty;
	swap(q,empty);
}
int main()
{
	// std::ios::sync_with_stdio(false);
	// std::cin.tie(0);
	int s,N,M,orow,ocol,erow,ecol;//N是橫的 M是直的
	Point ori,next;
	queue<Point> list;
	char c;
	cin>>s;
	for(int i=0;i<s;++i){
		cin>>N>>M>>orow>>ocol>>erow>>ecol;
		int map[N+1][M+1],ans[N+1][M+1];
		memset(ans,0,4*(N+1)*(M+1));//sizeof(ans)
		// cout<<list.empty()<<"?"<<endl;  //del
		clear(list);
		// cout<<list.empty()<<"A"<<endl; //del
		for(int i=1;i<=N;++i){
			for(int j=1;j<=M;++j){
				cin>>c;
				map[i][j]=c-'0';
			}//read in map
		}
		ori.row=orow;
		ori.col=ocol;
		ori.dis=1;
		ans[orow][ocol]=1;
		list.push(ori);
		while(!list.empty()){
			if(ans[erow][ecol]!=0){
				cout<<ans[erow][ecol]<<endl;
				// cout<<list.empty()<<'?'<<endl;
				break;
			}

			next=list.front();
			list.pop();
			// cout<<'A'<<endl;             //del
			for(int i=0;i<4;++i){
				int a=next.row+nov[i];
				int b=next.col+mov[i];
				if(!out(a,b,N,M)&&ans[a][b]==0&&map[a][b]==0){
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
		// for(int i=1;i<=N;++i){
		// 	for(int j=1;j<=M;++j)
		// 		cout<<ans[i][j]<<" ";
		// 	cout<<endl;
		// }
		if(ans[erow][ecol]==0)
			cout<<0<<endl;
		
	}


	return 0;
}