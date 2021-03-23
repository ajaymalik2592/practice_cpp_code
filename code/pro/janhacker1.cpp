#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<ll> a , b;
	a.resize(n),b.resize(n);
	for(int x= 0 ;x< n ;x++)cin>>a[x];
	ll mod = 1000000007,su = 0;
	for(int x= 0 ;x< n ;x++)cin>>b[x];
	sort(a.begin() , a.end());
	sort(b.begin() , b.end());
	for(int x= 0 ;x< n ;x++)su +=abs(a[x] - b[x])%mod, su%=mod;
	cout<<su<<"\n";
	
  	return 0;}
