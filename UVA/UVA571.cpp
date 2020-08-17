#include <iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
struct jug{
	int A;
	int B;
	vector<int> move;//1 fill A    2 fill B   3 empty A  
};					 //4 empty B   5 pour A B 6 pour B A
int Ca,Cb,N;
void pourA(int &A,int &B){
	if((Cb-B)>= A){
		B += A;
		A=0;
	}
	else{
		A -= Cb-B; 
		B = Cb;
	}
}
void pourB(int &A,int &B){
	if((Ca-A)>=B){
		A += B;
		B = 0;
	}
	else{
		B -= Ca-A;
		A = Ca;
	}
}
bool used[1001][1001];
int main(){
	while(cin>>Ca>>Cb>>N){
		queue<jug> list;
		jug ori,next;
		ori.A = Ca;
		ori.B = 0;
		ori.move.push_back(1);
		next.A = 0;
		next.B = Cb;
		next.move.push_back(2);
		list.push(ori);
		list.push(next);
		memset(used,false,sizeof(used));
		while(!list.empty()){
			next = list.front();
			list.pop();
			if(next.B == N)
				break;
			if(next.A == N){
				next.move.push_back(4);
				next.move.push_back(5);
				break; 
			}

			int a = next.A;
			int b = next.B;
			vector<int> c = next.move;
			if(a != Ca){//fill A
				if(!used[Ca][b]){
					ori.A = Ca;
					ori.B = b;
					ori.move = c;
					ori.move.push_back(1);
					list.push(ori);
					used[Ca][b]=true;
				}
			}
			if(b != Cb){//fill B
				if(!used[a][Cb]){
					ori.A = a;
					ori.B = Cb;
					ori.move = c;
					ori.move.push_back(2);
					list.push(ori);
					used[a][Cb]=true;
				}
			}
			if(a != 0){//empty A
				if(!used[0][b]){
					ori.A = 0;
					ori.B = b;
					ori.move = c;
					ori.move.push_back(3);
					list.push(ori);
					used[0][b]=true;
				}
			}
			if(b != 0){//empty B
				if(!used[a][0]){
					ori.A = a;
					ori.B = 0;
					ori.move = c;
					ori.move.push_back(4);
					list.push(ori);
					used[a][0]=true;
				}
			}
			if(a !=0 || b != Cb){
				ori.A = a;
				ori.B = b;
				ori.move = c;
				pourA(ori.A,ori.B);
				if(!used[ori.A][ori.B]){
					ori.move.push_back(5);
					list.push(ori);
					used[ori.A][ori.B]=true;
				}
			}
			if(b !=0 || a != Ca){
				ori.A = a;
				ori.B = b;
				ori.move = c;
				pourB(ori.A,ori.B);
				if(!used[ori.A][ori.B]){
					ori.move.push_back(6);
					list.push(ori);
					used[ori.A][ori.B]=true;
				}
			}
		}
		vector<int> ans = next.move;
		for(int i=0,n=ans.size();i<n;++i){
			switch(ans.at(i)){
				case 1:cout<<"fill A"<<endl;break;
				case 2:cout<<"fill B"<<endl;break;
				case 3:cout<<"empty A"<<endl;break;
				case 4:cout<<"empty B"<<endl;break;
				case 5:cout<<"pour A B"<<endl;break;
				case 6:cout<<"pour B A"<<endl;
			}
		}
		cout<<"success"<<endl;
	}
}