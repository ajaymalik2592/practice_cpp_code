#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()


ll gcd (ll a , ll b)
{
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}
vector <ll > prime {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main()
	{

		int n;
		cin >> n;
		vector < ll > a;
		a.resize(n);
		int e = 0;
		for(auto &b : a)
			{
				cin >> b;
				e += b;
			}
		sort(a.begin() , a.end());
		ll r = 0;
		ll c = 10000;
		for(int x =1 ; x< n ;x++)
		{
			c = a[0] + a[x];
			for(int y =  1 ; y <= a[x] ; y++ )
			{
				if(a[x] % y == 0)
				{
					c  = min (c , a[0]*y + a[x]/y );
					c =  min ( c, a[0]*a[x]/y + y );
				}
				r = max(r , a[0] + a[x] - c);
			}
			
		}
		cout << e - r << "\n";


	}