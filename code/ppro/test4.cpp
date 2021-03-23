#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

int main()
{

	speed
	int n, m;
	cin >> n >> m;
	vector< int > sta[n+1],psi;
	psi.resize(n+1);
	for(int x = 1 ; x< m+1 ; x++)
	{
		int i, j;
		cin >> i >> j;
		sta[i].pb(j);

	}
	int a1 = 0 ,a2 = 0;
	for(int x = 1 ; x<= n ;x++)
		{
			psi[x] = sta[x].size();
			if(psi[x] > a1)
			{
				a2 = a1;
				a1 = psi[x];
			}
			else if(psi[x] > a2)
			{
				a2 = psi[x];
			}
		}
	for(int x =1 ; x<= n ;x++)
	{
		int r = 0;
		for(int y = 1 ; y <= n && (psi[y] == a1 || psi[y] == a2) ; y++)
		{
			int re = y - x , temp = 1000000;
			if(re < 0)re += n;

			for(auto g : sta[y])
			{
				int u = g- y;
				if(u < 0) u+= n;
				temp   = min(temp , u);
			}
			if(sta[y].size() > 0)
			{
				re += temp + (sta[y].size() -1 )*n;
			}
			r = max(r , re);
			
		}
		cout << r <<" ";
	}

}

