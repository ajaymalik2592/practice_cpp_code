#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long unsigned ull;
template<typename t> t powe(t a , t b , t c){t re =1 ; while(b){if(b%2==1) re*=a, re%c;a*=a,a%=c, b>>=1;}return re;}
 
int main()
{ ll mod = 1000000007;
	ll tt;
	cin>>tt;
	while(tt--)
	{
		ll c,m,ra,k,p,c1,m1;
		cin>>c1>>m>>ra>>k;
		ll a[m],b[m];
		for(int x= 0 ;x< m ; x++)a[x] = 0;
		for(int x= 0 ;x< m ; x++)b[x] = 0;
		for(int x = 0 ; x< ra ; x++)
		{
			cin>>p>>c;
			if(c <= k)
				{a[p-1]+=1;
				}
				else {c--;
					c = c%(m+k-1 );
					c++;
					c-=k;
					c = max((ll)0,c);
					
					a[(p-1 + c + m)%m ]+=1;
					
				}
					
					
				
			
			
			}
			ll r = 0,r1=0;
			for(int x = 0 ; x< m ; x++)
			{if(a[x])r += m*a[x],r1+=a[x];
				
				b[x] = r;
				r-=r1;
			}
			
			for(int x = 0; x< m ; x++)
			{
				b[x] +=r;
				r1-=a[x];
				r-=r1;
				
				
				}
				ll j=0,sum = 0;
				for(int x=0 ; x< m ;x++)
				{if(b[x] > b[j])j=x ;
					
					}
					
			
		cout<<j+1<<" "<<b[j]<<endl;
	}
	
	return 0;
}
