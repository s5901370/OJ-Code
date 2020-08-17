#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
//#define debug
using namespace std;
int array[500005][2];
int find(int a){	
	return a==array[a][0]? a:(array[a][0]=find(array[a][0]));		
}
int isfriend(int a,int b){
	return find(a)==find(b);
}
int isenemy(int a,int b){
	return array[find(a)][1]==array[find(b)][0];
}
void u(int a,int b){
	int A=find(a),B=find(b);
	if(array[A][0]==array[B][0])
		return ;
	else if(array[A][0]==array[B][1])
		cout<<"angry"<<endl;
	else if(array[A][1]==0&&array[B][1]==0)	
		array[A][0]=B;
	else if(array[A][1]==0&&array[B][1]!=0)
		array[A][0]=array[B][0];
	else if(array[A][1]!=0&&array[B][1]==0)		
		array[B][0]=A;
	else{
		array[A][0]=B;
		array[array[A][1]][0]=array[B][1];
	}		
}
void enemy(int a,int b){
	int A=find(a),B=find(b);
	if(array[A][0]==array[B][0])
		cout<<"angry"<<endl;
	else if(array[A][1]==0&&array[B][1]==0){
		array[A][1]=B;
		array[B][1]=A;
	}
	else if(array[A][1]!=0&&array[B][1]==0)	
		array[B][0]=array[A][1];
	else if(array[A][1]==0&&array[B][1]!=0)
		array[A][0]=array[B][1];
	else{
		array[A][0]=array[B][1];
		array[array[A][1]][0]=B;
	}	
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string s1,s2,s3;
	int a,b,N;
	cin>>N;
	for(int i=1;i<=N;i++){
		array[i][0]=i;
		array[i][1]=0;		
	}
	while(cin>>s1){
		cin>>s2>>s3>>a>>b;	
		if(s1=="you"){
			if(s3=="friends"){
				u(a,b);
			}
			else if(s3=="enemies"){
				enemy(a,b);
			}
		}	
		if(s1=="are"){
			if(s3=="friends"){
				if(isfriend(a,b)){
					cout<<"yeap"<<endl;
				}
				else 
					cout<<"nope"<<endl;	
			}
			else if(s3=="enemies"){
				if(isenemy(a,b))
					cout<<"yeap"<<endl;
				else
					cout<<"nope"<<endl;	
			}
		}	
	#ifdef debug
		for(int i=1;i<=N;i++)
			cout<<i<<'='<<array[i][0]<<','<<array[i][1]<<endl;
		#endif
	}
	return 0;
}
	

