#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	int ans;
	while(cin>>s){
		int n=s.size();
		bool b=false;
		for(int i=0;i<n-1;++i){
			if(s[i+1]-s[i] < 0){
				cout<<0<<endl;
				b=true;
				break;
			}
		}
		if(b)continue;
		if(n == 1){
			cout<<s[0]-'a'+1<<endl;
			continue;
		}
		else if(n==2){
			int sum=26;
			int a=s[0]-'a';
			for(int i=25;i>=26-a;--i)
				sum+=i;
			sum+=s[1]-s[0];
			cout<<sum<<endl;
			continue;
		}
		else if(n==3){
			int sum=351;
			int a=s[0]-'a';
			for(int i=24;i>=25-a;i--)
				for(int j=1;j<=i;j++)
					sum+=j;
			for(int i=24-a;i>=26-s[1]+'a';--i)
				sum+=i;
			sum+=s[2]-s[1];
			cout<<sum<<endl;
			continue;
		}
		else if(n==4){
			int sum=2951;
			int a=s[0]-'a';
			for(int i=23;i>=24-a;i--)
				for(int j=1;j<=i;j++)
					for(int p=1;p<=j;p++)
						sum+=p;					
			for(int i=23-a;i>=25-s[1]+'a';i--)
				for(int j=1;j<=i;j++)
					sum+=j;
			for(int i=24-s[1]+'a';i>=26-s[2]+'a';--i)
				sum+=i;
			sum+=s[3]-s[2];
			cout<<sum<<endl;
			continue;
		}
		else{
			int sum=17901;
			int a=s[0]-'a';
			for(int i=22;i>=23-a;i--)
				for(int j=1;j<=i;j++)
					for(int p=1;p<=j;p++)
						for(int k=1;k<=p;k++)
							sum+=k;
			for(int i=22-a;i>=24-s[1]+'a';i--)
				for(int j=1;j<=i;j++)
					for(int k=1;k<=j;k++)
						sum+=k;
			for(int i=23-s[1]+'a';i>=25-s[2]+'a';i--)
				for(int j=1;j<=i;j++)
					sum+=j;
			for(int i=24-s[2]+'a';i>=26-s[3]+'a';--i)
				sum+=i;
			sum+=s[4]-s[3];
			cout<<sum<<endl;
			continue;
		}
	}
}