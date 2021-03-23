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
		int n,k;
		cin >> n >> k;
		vector< int > vec[n],tr[n];
		for(int x = 0; x<n;x++)
		{
			for(int y =0; y<n;y++)
			{
				int i;
				cin >> i;
				vec[x].pb(i);
				tr[x].pb(0);
			}
		}
		queue<pair<int ,int>> que;
		que.push(make_pair(1,1));
		int l =1, r = 1;
		while(k >= 0 && !que.empty())
		{
			pair<int,int> p= que.front();
			que.pop();
			int i = p.first, j = p.second;
			i--;
			j--;
			vector<int> h;
			if(j-1 >=0 && tr[i][j-1] == 0 && vec[i][j-1] <= k)
			{
				h.pb(make_pair(vec[i][j-1], 1));
			}
			if(j+1 <n && tr[i][j+1] == 0 && vec[i][j+1] <= k)
			{
				h.pb(make_pair(vec[i][j+1], 2));
			}
			if(i+1 < n && vec[i][j-1] <= k)
			{
				h.pb(make_pair(vec[i+1][j], 3));
			}
			sort(ALL(h));
			if(h.size() > 0)
			{
				p = h[0];
				k-= p.fisrt;
				if(p.second == 2)r = max(r, j + 1),tr[i][j+1] = 1, que.pb(mk(i +1, j+2));
				else if(p.second == 3)l = max(l, i +1), que.push(mk(i+2, j+1));
				else
					que.push(mk())

			}

		}
