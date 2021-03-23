#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
vector<long long > primes;
int p[100001];
void sieve(int a)
{
	for(int x =2; x<a; x++)
	{
		if(!p[x])
			{
				primes.pb(x);
				for(int y =x*2; y<a; y+=x)
					p[y] = 1;
			}

	}
}
int main()
{
	sieve(sqrt(2e9) + 10);
	int test;
	cin >> test;
	for(int test_cases = 1; test_cases<=test; test_cases++)
	{
		string s;
		ll a = 1000014129;
		cout << 1 << " " << 31623 << endl;
		ll d;
		cin >> d;
		a -= d;
		vector<ll> vec;

		for(auto x : primes)
		{
			if(x >= sqrt(1e9 ))break;
			if(x <= a && a % x == 0)
				vec.pb(x);
			while(a%x == 0)a /= x;
			if(x > a)break;
		}

		if(a > 1 && a < 1e9)
			vec.pb(a);
		ll ans;
		if(vec.size() == 1)
 		{
 			ans = vec[0];
		}
		else
		{
			
			int u = vec.size();
			long long h  = vec[u-1];
			
			for(auto pr: primes)
			{
				set<long long > se;
				for(auto a : vec)
					se.insert((pr*pr) % a);
				if(se.size() == u)
				{
					h = pr;
					// cout << "bantai rapper\n";
					// for(auto fir : se)
					// {
					// 	cout << fir << " ";
					// }
					break;
				}
			}


			cout << 1 << " " << h << endl;
			cin >> d;
			h = h*h;
			for(auto s1 : vec)
			{
				// cout << "s1 " << s1 << " % " <<  h % s1 << endl;
				if(h % s1 == d)
				{
					ans = s1;
					break;
				}
			}
		

		}
		cout << 2 << " " << ans << endl;
		cin >> s;

	}
}
