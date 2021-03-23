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
		speed
		int t;
		cin >> t;
		for(int test_case =1; test_case <= t; test_case ++)
		{
			int ans = 1;
			int n, m, k;
			cin >> n >> m >> k;
			int  rect[n+1][m+1], arr[n+1][m+1];
			for(int x =1; x <n+1; x++)
			{
				for(int y =1 ; y < m+1; y++)
				{
					cin >> arr[x][y];
				}
			}
			for(int x =1; x<n+1; x++)
			{
				for(int y =1; y < m+1; y++)
				{
					int a = arr[x][y], b = arr[x][y], index = y;
					for(int z =y+1; z <m +1; z++)
					{
						a = min(a, arr[x][z]);
						b = max(b, arr[x][z]);
						if(b - a  <= k)
							index = z;
						else
							break;
					}
					rect[x][y] = index  + 1 - y;
					
				}
			}
			for(int x =1; x< n+1; x++)
			{
				for(int y =1; y < m+1; y++)
				{
					int e = rect[x][y];
					ans = max(ans, e);
					for(int z =x +1; z <= n; z++)
					{
						e = min(e, rect[z][y]);
						ans = max(ans, e * (z-x+1));
						
					}
				}
			}
			cout << "Case #" << test_case << ": " << ans << "\n";
		}

}
