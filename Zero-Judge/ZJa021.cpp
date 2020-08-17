#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define SIZE 1000
char s1[SIZE],s2[SIZE];
int a1[SIZE],a2[SIZE],c[SIZE];
void add(){
	for(int i=0;i<SIZE-5;++i){
		c[i]+=a1[i]+a2[i];
		c[i+1]+=c[i]/10;
		c[i]%=10;
		}
	int len=SIZE-5;
	while(c[--len]==0&&len>0);
		for(int i=len;i>=0;--i)
			cout<<c[i];	
}
int compare(int x[],int y[] ){
	int i=SIZE-5;
	while(i>0&&x[i]==y[i])--i;
	return x[i]-y[i];
}
void mi(int len1,int len2){
	if(compare(a1,a2)>0){
	for(int i=0;i<SIZE-5;++i)
		c[i]+=a1[i]-a2[i];
	for(int i=0;i<SIZE-5;++i)	
		if(c[i]<0&&i<len1){
			c[i]+=10;
			c[i+1]--;
		} 
	int len=SIZE-5;
	while(c[--len]==0&&len>0);
	for(int i=len;i>=0;--i)
		cout<<c[i];		
	}
	else if(compare(a1,a2)==0)
		cout<<0;
	else{
		for(int i=0;i<SIZE-5;++i)
			c[i]+=a2[i]-a1[i];
		for(int i=0;i<SIZE-5;++i)	
			if(c[i]<0&&i<len2){
				c[i]+=10;
				c[i+1]--;
			} 
		
		int len=SIZE-5;
		while(c[--len]==0&&len>0);
		cout<<"-";
		for(int i=len;i>=0;--i)
			cout<<c[i];
	}
} 
void mul(){
	for(int i=0;i<strlen(s2);++i)
		for(int j=0;j<strlen(s1);++j)
			c[j+i]+=a1[j]*a2[i];
	for(int i=0;i<SIZE-5;++i){
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	int len=SIZE-5;
	while(c[--len]==0&&len>0);
	for(int i=len;i>=0;--i)
		cout<<c[i];	
}
int t[SIZE];
int test[SIZE];
void bigsub(int len){
	for(int i=0;i<SIZE-5;++i){
		a1[i]-=test[i];
		if(a1[i]<0&&i<len){
			a1[i]+=10;
			a1[i+1]--;
		} 
	}
}
void bigmul(int b,int delta){
	for(int i=0;i<(SIZE-5-delta);++i)
		test[i+delta]=t[i];
	for(int i=0;i<SIZE-5;++i)
		test[i]*=b;	
	for(int i=0;i<SIZE-5;++i){
		test[i+1]+=test[i]/10;
		test[i]%=10;
	}	
}
void div(){
	if(s2[0]=='0'){
		cout<<"nonsense";
		return ;
	}
	int delta=strlen(s1)-strlen(s2);	
	int record;
	for(int i=0;i<SIZE-5;++i)//t set
		t[i]=a2[i];
	for(int i=delta;i>=0;--i){
		for(int j=1;j<=9;++j){
			memset(test,0,4*SIZE);
			bigmul(j,i);
			int x=compare(a1,test);
			if(x>0){
				if(j==9){
					record=9;
					break;
				}
				else
					continue;
			}
			else if(x==0){
				record=j;
				break;
			}
			else{
				record=j-1;
				break;
			}	
		}
		c[i]+=record;
		if(record>0){
			memset(test,0,4*SIZE);
			bigmul(record,i);
			bigsub(strlen(s2)+delta);
		}
	}
	int len=SIZE-5;
	while(c[--len]==0&&len>0);
	for(int i=len;i>=0;--i)
		cout<<c[i];
}
int main(){
	char p;
	while(cin>>s1>>p>>s2){
		memset(a1,0,4*SIZE);
		memset(a2,0,4*SIZE);
		memset(c,0,4*SIZE);
		for(int i=0;i<strlen(s1);++i)
			a1[i]=s1[strlen(s1)-i-1]-'0';
		for(int i=0;i<strlen(s2);++i)
			a2[i]=s2[strlen(s2)-i-1]-'0';
		switch(p){
			case '+':
				add();break;
			case '-':
				mi(strlen(s1),strlen(s2));break;
			case '*':
				mul();break;
			case '/':		
				div();break;	
		}
		cout<<endl;
	}
}
