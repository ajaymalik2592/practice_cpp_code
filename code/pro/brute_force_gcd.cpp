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
		ll n ;
		cin >> n;
		vector<vector<ll>> vec(n+1, {0,0});
		for(int f = 0; f <n; f++)
		{
			int y, f1;
			cin >> y >> f1 ;
			vec[y][f1]++;
		}
		vector< pair< ll , pair<ll, ll >   > >  v;
		for(auto a : vec)
		{	
			int s = a[0] + a[1];
			if(s > 0)
				v.push_back({s, {a[1], a[0]}});
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int f =  v[0].first-1, ans =v[0].first, ans1 = v[0].second.first;
		for(int x = 1; x< v.size(); x++)
		{
			int a = v[x].first;
			if(a >= f)
			{
				
				ans += f;
				f--;
				ans1 += v[x].second.first;
			}
			else
			{
				f = a -1;

				ans += a;
				ans1 += v[x].second.first;
			}
			if(f <= 0)break;
		}
		cout << ans << " " << ans1 <<  "\n";

	}
	
}