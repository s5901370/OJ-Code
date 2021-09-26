#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin>>N;
	long long int weight[N];
	long long int sum =0;
	for (int i = 0; i < N; ++i)
	{
		cin>>weight[i];
		sum += weight[i];
	}
	// cout<<endl<<sum<<endl<<endl;
	long long int up = sqrt(sum);
	vector<long long int> num;
	// long int count=0;
	for (long long int i = 1; i <= up; ++i)
	{
		if(sum%i == 0){
			num.push_back(i);
			if(i*i != sum)
				num.push_back(sum/i);
			// printf("%lld %lld\n",i,sum/i);
		}
		/* code */
	}
	int range_min=N;
	for (int i = 0; i < num.size(); ++i)
	{
		int flag = 1;
		int j=0;
		long long int s=0; //local sum
		int range=0;
		int range_max=0;
		while(flag && j<N){
			s+=weight[j++];
			++range;
				// cout<<range<<endl;
			if(s == num[i]){
				range_max = range > range_max ? range:range_max;
				range=0;
				s=0;
			}
			else if(s>num[i]){
				flag=0;
				range_max = N;
			}
		}
		range_min = range_max < range_min? range_max:range_min;
		// cout<<num[i]<<" min = "<<range_min<<endl;
		/* code */
	}

	cout<<range_min<<endl;
}