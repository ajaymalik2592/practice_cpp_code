#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod =1e9 + 7;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n,k; cin >>  n >> k;
		vector<ll> vec(n);
		ll m1 = 1e9 , m2 = 0;
		for(auto &d : vec)
		{
			cin >> d;
			m2 = max(d, m2);
			m1 = min(m1 , d);

		}
		ll j = m2 - m1;
		if( j % 2 == 0 && j/2 <= k)
			cout << m1 + k << "\n";
		else if( j%2 == 1 && j/2 +1 <= k)
			cout << m1 + k << "\n";
		else
			cout << -1 << "\n";
	}
	
}