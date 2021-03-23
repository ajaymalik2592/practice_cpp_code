#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll summ , limit;
	cin>>summ>>limit;
	ll r = log2(limit);
	vector<ll> v;
	if(pow(2 , r+1) -1 < summ)
	{ cout<<-1<<endl; return 0; }
	else{
		
		ll r =1;
		while(summ)
			{
				if(summ%2==1){
					v.push_back(r);
					}
				summ/=2;
				r*=2;
			}
		}
	
	cout<<v.size()<<endl;
	for(vector<ll> ::iterator it = v.begin() ; it != v.end() ; it++)
	{
		cout<<*it<<" ";
		}
		cout<<endl;
	return 0;
}
