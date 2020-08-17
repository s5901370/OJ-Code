#include<iostream>
#include<string> 
#include<cstdlib>//abs
using namespace std;
void printnumber(int s){
	if(s==0){
		cout<<"ZERO"<<endl;
		return;
	}
	int a,b,c,d;
	a=s/1000;
	s%=1000;
	b=s/100;
	s%=100;
	c=s/10;
	d=s%10;
	for(int i=0;i<a;i++)
		cout<<"M";
	if(b==9)
		cout<<"CM";
	else if(b<9&&b>=5){
		cout<<"D";
		for(int i=0;i<(b%5);i++)
			cout<<"C";
	}
	else if(b==4)
		cout<<"CD";
	else
		for(int i=0;i<b;i++)
			cout<<"C";
			
	if(c==9)
		cout<<"XC";
	else if(c<9&&c>=5){
		cout<<"L";
		for(int i=0;i<(c%5);i++)
			cout<<"X";
	}
	else if(c==4)
		cout<<"XL";
	else
		for(int i=0;i<c;i++)
			cout<<"X";
	
	if(d==9)
		cout<<"IX";
	else if(d<9&&d>=5){
		cout<<"V";
		for(int i=0;i<(d%5);i++)
			cout<<"I";
	}
	else if(d==4)
		cout<<"IV";
	else
		for(int i=0;i<d;i++)
			cout<<"I";
	cout<<endl;		
}
int trans(string s){
	int sum=0;
	for(int i=0;i<s.length();i++){
		switch(s[i]){
			case 'M':sum+=1000;
				break;
			case 'D':sum+=500;
				break;
			case 'C':if(s[i+1]=='D'){
					sum+=400;
					i++;
					break;
				}
				else if(s[i+1]=='M'){
					sum+=900;
					i++;
					break;
				}
				else
					sum+=100;
				break;
			case 'L':sum+=50;
				break;
			case 'X':if(s[i+1]=='C'){
					sum+=90;
					i++;
					break;
				}
				else if(s[i+1]=='L'){
					sum+=40;
					i++;
					break;
				}
				else
					sum+=10;
				break;
			case 'V':sum+=5;
				break;
			case 'I':if(s[i+1]=='X'){
					sum+=9;
					i++;
					break;
				}
				else if(s[i+1]=='V'){
					sum+=4;
					i++;
					break;
				}
				else
					sum+=1;
				break;
		}
	}
	return sum;
}
int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string s1,s2;
    while(cin>>s1){
    	if(s1=="#")
    		return 0;
    	cin>>s2;
		int a=trans(s1),b=trans(s2);	
		printnumber(abs(a-b));
	}
} 
