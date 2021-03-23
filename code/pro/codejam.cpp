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
		for(int in = 1; in <= t; in++)
		{
			cout  << "Case #" << in << ": ";

			ll r[6], r1 [6], p[6];

			for(int x=0; < 6 ; x++)
			{
				cout << x +1 << "\n";
				cin >> r[x];
			}
			for(int x =1; x < 6 ;x++)
			{
				p[x] = r[x] - r[x -1];
			} 
			r1[0] = (p[3] - 2 * p[1]) / 4;
			for(int x =0; x < 6 ;x++)
			{
				r[x] -= r1[0] * pow(2 , x +1 );

			}
			 
			cout << yy  << " "<<  xx << "\n";
			
		
		}
	}

