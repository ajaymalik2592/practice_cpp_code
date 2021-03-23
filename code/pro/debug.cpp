#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

ll power(ll a , ll b , ll d){ll re =1 ; while(b){if(b%2 == 1)re*=a, re%=d; a*=a ; a%=d ; b>>=1;} return re;}

int main()
	{
		ll d = 1000*1000*1000 + 7 , c = 5;
		ll e[10] = {187500002,
					750000006,
					171875002,
					23437501,
					304687503,
					158203127,
					655273443,
					867187507,
					97412111,
					765502936};
		for(ll x = 4 ; x <14 ;x++)
		{
			ll w =( power((ll)2 , x  , d) * e[x-4] ) % d ;
			cout <<w<<"\n";
		}
	}