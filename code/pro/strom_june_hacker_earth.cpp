#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
int main()
	{
		int t;
		cin >> t;
		while(t--)
		{
			ll n, k;
			cin >> n >> k;
			vector<ll> vec(n), vec1;
			set<int> se;
			for(auto &s : vec)
				cin >> s, se.insert(s);
			int sum = n;
			for(int x= 1; x<= k; x++)
				vec1.pb(x);
			do{
				int f = 0;
				for(int x=0; x<n; x++)
				{
					if(vec[x] != vec1[x%k])f++;
				}
				sum = min(sum , f);
			}
			while(next_permutation(ALL(vec1)));

			cout << sum << endl;
		}
	}
