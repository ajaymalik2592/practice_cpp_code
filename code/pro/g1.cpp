#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
bool comp(pair<ll , ll >a , pair<ll , ll> b)
{
	return a.second < b.second;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	deque<int> q;
	int n , q1;
	cin >> n >> q1;
	vector<int> vec(n), v(n-1), ans(n);
	int t = 0, s = -1, f = 0;
	for(auto &a : vec)
		{
			cin >> a;
			if(s < a)
			{
				s = a;
				f = t;
			}
			t++;
			q.push_back(a);

		}
	vector< pair<int , int > > pa;
	for(int x = 0; x<f; x++)
	{
		int a = q.front();
		q.pop_front();
		int b = q.front();
		q.pop_front();
		pa.push_back({a,b});
		if(a > b)q.push_front(a), q.push_back(b);
		else q.push_front(b), q.push_back(a);
	}
	int an = q.front();
	q.pop_front();
	for(int x = 1; x<n; x++)
	{
		ans[x-1] = q.front();
		q.pop_front();
	}
	while(q1--)
	{
		ll m;
		cin >> m;
		if(m <= f)
		{
			cout << pa[m-1].first << " " << pa[m-1].second <<"\n";
		}
		else
		{
			m-=f+1;
			cout << an << " " << ans[(m)%(n-1)] <<"\n";
		}
	}

}