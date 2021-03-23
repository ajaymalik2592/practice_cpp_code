#include<bits/stdc++.h>
using namespace std;
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ALL(v)   v.begin(),v.end()
typedef long long ll;
int main()
	{
		
		ll n, mod = 998244353;
		cin >> n;
		vector <ll> a(n),b(n),c(n);
		for(auto &s : a)
			cin >> s;
		for(auto &s : b)
			cin >> s;
		ll s = 0,n1=0;
		for(int x=0; x < n;x++)
		{
			n1 = (n-x) * (x + 1);
			a[x] =(a[x]* n1) ;
		}
		sort(ALL(a));
		sort(ALL(b));
		reverse(ALL(b));
		
		for(int x=0; x <n; x++)
		{
			s += ((a[x] % mod )* b[x]) % mod;
			s %= mod;
		}
		
		cout << s % mod ;

	}
