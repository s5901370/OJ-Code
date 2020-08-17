#include <iostream>
#include <queue>
using namespace std;
// back()
// front()
// empty()
// pop()
// push()
// size()
int main(){
	queue<int> q1;
	int a;
	for(int i=0;i<5;i++){
		cin>>a;
		q1.push(a);
	}
	for (int i = 0; i < 5; ++i)
	{
		cout<<q1.front();
		q1.pop();
	}
	cout<<endl<<q1.empty();
}