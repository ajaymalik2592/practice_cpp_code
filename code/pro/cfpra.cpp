#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back

int main()
	{	//cout<<-1/3<<endl;
		ll n,l,r,mod =1000000007;
		cin>>n>>l>>r;
		ll dp[n][3] , c[3];
		c[0]=0,c[1] = 0,c[2] = 0;
		int y  =l;
		while(y%3 != r%3)
		{	
			c[y%3]++,y++;
		}
		
		c[y%3]++;
		
		y = (r-y)/3;
		
		c[0]+=y,c[1]+=y,c[2]+=y;
		//cout<<c[0] <<" "<<c[1]<<" "<<c[2]<<"\n";
		dp[0][0] = c[0] , dp[0][1] = c[1] , dp[0][2] = c[2];
		for(int x= 1 ; x< n ;x++)
			{
				dp[x][0] = (dp[x-1][0]*dp[0][0] + dp[x-1][1]*dp[0][2] + dp[x-1][2]*dp[0][1])%mod;
				
				dp[x][1] = (dp[x-1][0]*dp[0][1] + dp[x-1][1]*dp[0][0] + dp[x-1][2]*dp[0][2])%mod;
			
				dp[x][2] = (dp[x-1][0]*dp[0][2] + dp[x-1][1]*dp[0][1] + dp[x-1][2]*dp[0][0])%mod;
			
			}
			
		cout<<dp[n-1][0]<<"\n";
			
		return 0;
	}
