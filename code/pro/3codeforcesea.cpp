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
vector<int> vec(300005), index1(300005);
void swapi(int x, int y)
{
	int x1 = vec[x], y1 =vec[y];
	index1[x1] = y;
	index1[y1] = x;
	vec[x] = y1;
	vec[y] = x1;

}
int main()
	{
		int n;
		cin >> n;
		
		for(int x =1; x <n+1; x++)
		{
			cin >> vec[x];
			index1[vec[x]] = x;
		}
		vector<pair<int, int>> pa;
		int m =0;
		for(int x =1; x< n+1; x++)
		{
			if(vec[x] == x)continue;
			int a, b ;
			if(x <= n/2)
			{
				if(index1[x] - x >= n/2)
				{
					pa.pb(make_pair(x,index1[x]));
					swapi(x,index1[x]);
					m++;

				}

				else
				{
					if(index1[x] + n/2 <= n)
					{
						a = index1[x], b = n;
						pa.pb(make_pair(index1[x], n));
						swapi(index1[x], n);
						pa.pb(make_pair(x,n));
						swapi(x,n);
						m+=2;
						pa.pb(make_pair(a, b));
						swapi(a, b);
						m++;
					}
					else
					{
						m+=3;
						a = 1, b = index1[x];
						pa.pb(make_pair(1,index1[x]));
						swapi(1,index1[x]);
						pa.pb(make_pair(index1[x], n));
						swapi(index1[x], n);
						pa.pb(make_pair(x,n));
						swapi(x,n);
						pa.pb(make_pair(a, b));
						swapi(a, b);
						m++;
					}
				}
			}
			else
			{
				if(x - index1[x] >= n/2)
				{
					pa.pb(make_pair(x,index1[x]));
					swapi(x,index1[x]);
					m++;

				}
				else
				{
					if(index1[x]  > n/2 )
					{
						a = index1[x], b = 1;
						pa.pb(make_pair(index1[x], 1));
						swapi(index1[x], 1);
						pa.pb(make_pair(x,1));
						swapi(1,x);
						m+=2;
						pa.pb(make_pair(a, b));
						swapi(a, b);
						m++;
					}
					else
					{
						m+=3;
						a = index1[x], b = n;
						pa.pb(make_pair(n,index1[x]));
						swapi(n,index1[x]);
						pa.pb(make_pair(1, n));
						swapi(n, 1);
						pa.pb(make_pair(x,1));
						swapi(1,n);
						pa.pb(make_pair(a, b));
						swapi(a, b);
						m++;
					}
				}
			}
			
				
		}
		cout << m << "\n";
		for(auto t : pa)
		{
			cout << t.first << " " << t.second << "\n";
		}

	}
