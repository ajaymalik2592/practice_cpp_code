#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long unsigned ull;
template<typename t> t powe(t a , t b , t c){t re =1 ; while(b){if(b%2==1) re*=a, re%c;a*=a,a%=c, b>>=1;}return re;}
 
vector< vector <ll > > mull( vector< vector <ll > > a  , vector< vector <ll > > b  ,  ll mod)
{
	vector< vector < ll > > c(5 , vector<ll> (5));
	for(int x= 0 ; x < 5 ; x++)
	{for(int y  = 0 ; y< 5 ; y++)
		{
			for(int z = 0 ; z< 5 ; z++)
			{
				c[x][y]  += (a[x][z] * b[z][y] )%mod;
				c[x][y] %=mod;
				}
			}
		}
		return c;
	
	}
	
vector< vector <ll > > power(vector< vector <ll > > t , ll n , ll mod)
{
	vector< vector <ll > >  w {{1,0,0,0,0},{0,1,0,0,0} , {0,0,1,0,0} ,{0,0,0,1,0},{0,0,0,0,1}};
	while(n)
	{if(n%2==1)
		{
			w  = mull(w,t,mod);
			}
			t = mull(t,t,mod);
			n>>=1;
		
	}
		return w;
	
	}
 
int main()
{ ll mod = 1000000007;
	vector< vector <ll > > t {{0,1,0,0,0},{0,0,1,0,0} , {3,0,1,2,0} ,{0,0,0,1,1},{0,0,0,0,1}};
	int tt;
	cin>>tt;
	while(tt--)
	{ll f0,f1,f2,y;
		cin>>f0>>f1>>f2>>y;
		
		vector<vector < ll> > r = power(t , y , mod);
		ll re = r[0][0] * f0 + r[0][1] * f1 + r[0][2] * f2 + r[0][3]*3 + r[0][4] ;
		re%=mod;
		cout<<re<<endl;
		
		}
	
	
	return 0;
}
