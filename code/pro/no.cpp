#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
int gcd(ll a, ll b)
{
	if(b == 0) return a;
	else gcd(b, a%b);
}
int main()
	{
		int t;
		cin >> t;
		while(t--)
		{
			int n;
			cin >> n;
			vector<ll> vec;
			set<ll> se;
			for(int x=0; x<n; x++)
			{
				ll a;
				cin >> a;
				se.insert(a);
			}
			if(se.size() == 1)
			{
				cout << 2 * (*se.begin()) << "\n";
			}
			else
			{
				ll sum = 0;
				n = se.size();
				vector<ll> forward(n), backward(n), arr;
				for(auto a : se)
					arr.pb(a);
				backward[n-1] = arr[n-1];
				forward[0] = arr[0];
				for(int x=n-2; x>= 0; x--)
				{
					backward[x] = gcd(backward[x+1], arr[x]);

				}
				for(int x=0; x< n;x++)
				{
					if(x == 0)
					{
						sum = max(sum, arr[0] + backward[1]);
					}
					else if(x == n-1)
					{
						sum = max(sum, arr[n-1] + forward[n-2]);
					}
					else
					{
						forward[x] = gcd(forward[x-1] , arr[x]);
						sum = max(sum, arr[x]  + gcd(forward[x-1] , backward[x+1]));
					}
				}
				
				cout << sum << "\n";
			}
		}
		return 0;
	}
