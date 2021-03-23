#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define mk make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()

int visited[100005], n, c[100005];
vector <int> res;

int main()
	{
		cin >> n;
		vector<int> vec[n];
		int root;
		res.clear();
		for(int x= 0; x<n ;x++)
		{
			int i, j;
			cin >> i >> j;
			if(i == -1)
			{
			continue;
			}
			i--;
			c[x] = j;
			visited[x] = i;
			vec[x].pb(i);
			vec[i].pb(x);
		}
		for(int x =0 ; x<n ;x++)
		{
			int de =0;
			for(auto l : vec[x])
			{
				if(c[l] == 0 && visited[x] != l)
					de = 1;
			}
			if(de==0 && c[x] )
				res.pb(x);
		}
		if(res.size())
		{
			// cout << res.size() << "\n";
			sort(ALL(res));
			for(auto gf : res)
				cout << gf +1 << " ";
		}
		else
			cout <<  -1;
		
	}

