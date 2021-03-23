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
ll mod = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if(b == 0)return a;
    else return gcd(b, a%b);
}
int main()
	{
	    ll t;cin >>t;
	    while(t--)
	    {
	    	
	        
	        
	        
	        for(int f = 1; f<= 100; f++)
	        {
	        	ll n, ans = 0;
	        	n = f;
	        
		        for(int x =1; x<= n; x++)
		        {
		            for(int y = x+1; y<=n; y++)
		            {
		               
		                for(int z =y+1; z<= n; z++)
		                {
		                    
		                    for(int a = z+1; a<=n; a++)
		                    {
		                        ll s2 = gcd(gcd(x,y), gcd(z,a));
		                        // if(s2 == 2)
		                        // 	vec[x] ++;
		                         s2 *= s2;
		                         s2 %= mod;
		                         s2*=s2;
		                         ans += s2%mod;
		                    }
		                }
		            }
		        }
	      
	        cout << ans % mod<< " , ";
	    }
	    }
	    
		return 0;
		
	}