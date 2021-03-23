#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ALL(v) v.begin(), v.end()
typedef long long ll;
ll mod = 1e9 + 7;
bool comp (pair<int, int> a , pair<int, int> b)
{
	return a.second > b.second;
}
typedef ld long double;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	cout << fixed << setprecision(15);
	while(t--)
	{
		ll n, l , v;
		cin >> n >> l >> v;
		ld left = 0 , right = l; 
		vector<ld> position(n), speed(n);
		for(auto &a : position)cin >> a, left = max(a, left), right = min(a, right);
		for(auto &a : speed)cin >> a;
		int t1 = 0 , t2;
		ld pos = 0, pos1 = right;

		for(int x =1; x<100; x++)
		{
			ld p= pos + (pos1 - pos)/2;
			vector<pair<ld, int>> v1(n), v2(n);
			for(int y = 0; y<n ;x++)
			{
				v1[x].first = (position[x] - pos)/ speed[x];
				v1[x].second = x;
				v2[x].first = (l - position[x] + pos)/speed[x];
				v2[x].second = x;
			}
			sort(ALL(v2));
			sort(ALL(v1));
			if(v2[0].second != v1[0].second)
			{
				t1 =  min(v2[0].first - v1[0].first) + abs(v2[0].first - v1[0].first) /2;
			}
			else
			{
				t1 = min(v2[1].first - v1[0].first) + abs(v2[1].first - v1[0].first) /2;
				t1 = min(t1, min(v2[0].first - v1[1].first) + abs(v2[0].first - v1[1].first) /2);
			}


		}
		pos = left , pos = l;
		for(int x =1; x<100; x++)
		{
			ld = pos + (pos1 - pos)/2;
			vector<pair<ld, int>> v1(n), v2(n);
			for(int y = 0; y<n ;x++)
			{
				v1[x].first = (position[x] - pos)/ speed[x];
				v1[x].second = x;
				v2[x].first = (l - position[x] + pos)/speed[x];
				v2[x].second = x;
			}
			sort(ALL(v2));
			sort(ALL(v1));
			if(v2[0].second != v1[0].second)
			{
				t2 =  min(v2[0].first - v1[0].first) + abs(v2[0].first - v1[0].first) /2;
			}
			else
			{
				t2 = min(v2[1].first - v1[0].first) + abs(v2[1].first - v1[0].first) /2;
				t2 = min(t1, min(v2[0].first - v1[1].first) + abs(v2[0].first - v1[1].first) /2);
			}
			

		}
	}
	return 0;
}