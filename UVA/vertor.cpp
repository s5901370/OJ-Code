#include<iostream>
#include<vector>
#include<string>
#define MAX 30
using namespace std;
vector<int>array[MAX];
int n;
void find(int a,int &p1,int &p2){
	for(p1=0;p1<n;p1++)
		for(p2=0;p2<array[p1].size();p2++)
			if(array[p1][p2]==a)
				return;
}
void clear_block(int p1,int p2){
	for(int i=p2+1;i<array[p1].size();i++){
		int b=array[p1][i];
		array[b].push_back(b);
	}
	array[p1].resize(p2+1);
}
void move_block(int a,int a1,int b){//a的位子 b的陣列 
//	cout<<"a1="<<a1<<" size="<<array[a].size();
	if(a==b)return;
	for(int i=a1;i<array[a].size();i++){
		array[b].push_back(array[a][i]);
		}
	array[a].resize(a1);//resize
	
}

int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int p1,p2,h1,h2;
	string s1,s2;
	while(cin>>n){
		int x,y;
		for(int i=0;i<n;i++){
			array[i].clear();//clear
			array[i].push_back(i);//push_back
		}
		while(cin>>s1){
			if(s1=="quit")break;
			cin>>x>>s2>>y;
			if(x==y)continue;
			find(x,p1,p2);
			find(y,h1,h2);
			if(s1=="move")
				clear_block(p1,p2);
			if(s2=="onto")
				clear_block(h1,h2);
			move_block(p1,p2,h1);	
		}
		for(int i=0;i<n;i++){
			cout<<i<<":";
			for(int j=0;j<array[i].size();j++)
				cout<<" "<<array[i][j];
			cout<<endl;	
		}
	}
} 
