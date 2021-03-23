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
	int t;
	cin >> t;
	while(t--)
	{
		int n , m , px , py;
		cin >> n >> m >> px >> py;
		int a[n +1][m +1];
		for(int x = 0 ;x< n ; x++)
		{
			for(int y = 0 ;y < m ;y ++)
			{
				char c;
				cin >> c;
				if(c == '0')a[x][y] = 0;
				else a[x][y] = 1;
			}
		}
		int i = 0;
		for(int x = 0 ; x< m ;x+= 3)
		{
			a[0][x] = i;
			i  = i + 2;
		}
		
		for(int x =2 ; x< m ;x++)
			a[x][0] = a[x-1][0] +1;
		for(int x = 0 ;x< n ; x++)
		{
			for(int y = 0 ;y < m ;y ++)
			{
				if(x == 0  && y == 0)
					{   cout << 0 <<" ";
						a[1][0] = 3;
				}
				else if(y %3  == 0)
				{
					cout << a[x][y] << " " ;
					a[x+1][y]  = a[x][y] +1;
				}
				else cout << -1 << " ";
			}
			cout << "\n";
		}

	}

	}
