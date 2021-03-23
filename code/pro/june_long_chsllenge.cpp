#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1e9 + 7;
ll power(ll a, ll b)
{
	ll re =1;
	while(b)
	{
		if(b&1)
		{
			re *= a;
			re %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return re;
}
bool comp (pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}
int main()
{
	ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
	ll n, q;
	cin >> n >> q;
	vector<ll> vec(300005),vec1(300005);
	vec[0] = 1; 
	vec1[0] = 1;
	for(int x =1; x < n +5; x++)
		vec[x] = (vec[x-1] * x) % mod, vec1[x] = power(vec[x], mod-2);
	
	if(n < 2000)
	{
		vector<pair<ll, ll>> pa(n);
		vector<int> index, check;
		for(int x=0; x<n; x++)
		{
			cin >> pa[x].first;
			pa[x].second = x;
		}
		ll result = 0;
		int num=0, val =pa[0].first;
		sort(pa.begin(), pa.end());
		for(int x=0; x<n; x++)
		{
			if(val == pa[x].first)num++;
			else
			{
				check.push_back(num);
				val = pa[x].first;
				num=1;
			}
			index.push_back(pa[x].second);

		}
		if(num > 0)
			check.push_back(num);
		while(q--)
		{
			int l1,l2,r1,r2;
			cin >> l1 >> l2 >> r1 >> r2;
			ll l = (l1 * result + l2) % n, r = (r1 * result + r2) % n;
			if(l > r)
			{
				l = l + r;
				r = l - r;
				l = l - r;

			}

			result = vec[abs(l - r) +1];
			int start = 0;
			for(auto j : check)
			{
				result = (result * vec1[upper_bound(index.begin() + start, index.begin() + j+start , r) - lower_bound(index.begin() + start, index.begin() +start + j , l)])  % mod;
				start += j;
			}
			cout << result << "\n";
		}
		return 0;
	}

	vector<pair<int, int>> pa(n);
	
	for(int x=0; x<n; x++)
	{
		cin >> pa[x].first;
		pa[x].second = x;
	}
	sort(pa.begin(), pa.end());
	int u = -1, in = -1;
	int ff = 0;
	vector<int> v;
	int o = 0;
	for(auto &a : pa)
	{	
		if(a.first != u)
		{
			if(u != -1)
				v.pb(o);
			in++;
			u = a.first;
			ff++;
		}
		a.first = in;
		o++;
	}
	v.pb(o);
	// sort(pa.begin(), pa.end(), comp);
	ll ans = 0;
	if(ff != n)
	for(int x=0; x<q; x++)
	{
		vector<int> index(ff, 0);
		ll i,j,i1,j1;
		cin >> i1 >> i >> j1 >> j;
		j%=n, i %= n;
		if(i > j)swap(i ,j );
		ll result = 1;
		// for(int y = i; y<= j ; y++)
		// {
		// 	int r = index[pa[y].first]++;
		// 	result *= vec[r];
		// 	result%=mod;
		// 	result *= vec1[r+1];
		// 	result%=mod;
		// }
		// ans = (vec[j+1-i] * result ) % mod;
		// cout << ans << "\n";
		int h = 0;
		for(int x : v)
		{
			result *= vec[]
			h = x;
		}

	}
	else
	{
	ans = 0;
	for(int x=0; x<q; x++)
		{
			
			ll i,j,i1,j1;
			cin >> i1 >> i >> j1 >> j;
			j = (j + ans * j1 ) %n, i = (i + ans * i1) %n;
			if(i > j)swap(i ,j );
			
			ans = vec[j+1-i];
			cout << ans << "\n"; 

		}
	}
	

	return 0;
}