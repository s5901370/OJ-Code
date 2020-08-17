#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX 100005
#include<map>

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n,a=1;
	string s;
	map<string,int>mapword;
	map<string,int>::iterator it;
	while(cin>>n){
		mapword.clear();
		a=1;
//		cout<<"A";
		for(int i=0;i<n;i++){
			cin>>s;
//			cout<<"i="<<i;
			it=mapword.find(s);
			if(it!=mapword.end())
				cout<<"Old! "<<it->second<<endl;
			else{
				mapword[s]=a;
				cout<<"New! "<<a<<endl;
				a++;
			}
		}
	}
		
	}
	

