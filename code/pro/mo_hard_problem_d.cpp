#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll block_size = 500;
struct query
{
	ll l,r,index;
	bool operator< (query a)
	{
		return make_pair(l / block_size , r) < make_pair(a.l / block_size, a.r);
	}

};
ll cal(ll a)
{
	return ((a+1)*(a+1) - a*a);
}
void  MO (vector<query> que, vector<ll> arr)
{
	sort(que.begin(), que.end());
	int L = 0, R = 0;
	vector<ll> ma(1000005,0);
	ma[arr[0]] = 1;
	ll ans = arr[0];
	vector<ll> answer(que.size());
	for(int x = 0; x <que.size(); x++)
	{
		int l = que[x].l , r = que[x].r ;

		while(L > l)
		{
			L--;
			ans += arr[L]*( cal(ma[arr[L]]));
			++ma[arr[L]];
			
		}
		while(R < r)
		{
			R++;
			ans += arr[R]*(cal(ma[arr[R]]));
			ma[arr[R]]++;
			
		}
		while(L < l)
		{
			ma[arr[L]]--;
			ans -= arr[L]*(cal(ma[arr[L]]));
			
			L++;
		}
		while(R > r)
		{
			--ma[arr[R]];
			ans -= arr[R]*( cal(ma[arr[R]]));
			
			R--;
		}
		
		answer[que[x].index] = ans;
	}
	for(auto s : answer)
		printf("%lld\n",s);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	cin >> n >> t;
	block_size = sqrt(n);
	vector<ll> vec(n);
	for(auto &a : vec)cin >>a;
	vector <query> que;
	for(int x = 0; x<t;x++)
	{
		query q;
		scanf("%lld%lld",&q.l,&q.r);
		q.l--,q.r--;
		q.index = x;
		que.push_back(q);
	}
	MO(que, vec);

}