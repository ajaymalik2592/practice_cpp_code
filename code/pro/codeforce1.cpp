
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long unsigned ull;
template<typename t> t power(t a , t b , t c){t re =1 ; while(b){if(b%2==1) re*=a, re%c;a*=a,a%=c, b>>=1;}return re;}
ll gcd(ll a , ll b)
{if(b==0)return a;
	else return gcd(b,a%b);
	}
int main()
{
	int n;
	
	 ll dp[1001][10001];
	 for(int x =  0 ; x  < 1001 ; x++)dp[x][0] = 1,dp[x][x] = 1;
	 for(int x = 2  ; x< 10001 ; x++)
	 {
		 ll d =1,q =1 , l = x;
		 for(int y = 1 ; y < x ; y++)
		 {
			 q*=l;
			 l--;
			 d*= y;
			 d%=mod , q %= mod;
			 dp[x][y]  = (q* power(q,mod-2 , mod))%mod;
			 
		 }
	  }
	  
	  
	
	return 0;
}
