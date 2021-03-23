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
int main()
{
	ll n;
	cin >> n;
	vector<long double> vec(n);
	vector<int> v(n);
	long double d = 0;
	for(int x =0; x<n ;x++)
	{
		cin >> vec[x];
		int u = vec[x];
		if(u == vec[x])
			v[x]  = u, d += vec[x] - u;
		else
		{
			if(d == 0)
			{
				int k = floor(vec[x]);
				v[x] =  k;
				d  = vec[x] - k;

			}
			else if(d < 0)
			{
				int k = floor(vec[x]);
				d += vec[x] - k;
				v[x] = k;
			}
			else
			{
				int k = floor(vec[x]) + 1;
				d += vec[x] - k;
				v[x] = k;
			}
		}
	}
	for(auto d1 : v)
		cout << d1 << "\n";
	return 0;
}