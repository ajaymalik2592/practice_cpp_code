#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
ll gcd(ll a , ll b)
{
	if(b== 0 )return a;
	return gcd(b , a % b);
}
int main()
{
	int t;
	cin >> t ;
	while(t--)
	{
		ll n , k , a , b ;
		cin >> n  >> a >> b >> k ;
		ll lc = (a*b)/gcd(a,b);
		if(k <= n/ a + n / b - 2*n/(lc))
			cout << "Win\n";
		else cout << "Lose\n";
	}
	return 0;
}