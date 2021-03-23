#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = (int )a  ; i <= (int)b ; i+=1)
#define R(i,a,b) for(int  i = (int )a ; i>=(int)b ; i-=1)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	ll a[n][m];
	F(x,0,n-1) F(y,0,m-1) cin>>a[x][y];
	F(x,1,m-1)a[0][x] +=a[0][x-1];
	F(x,1,m-1)a[x][0] +=a[x-1][0];
	F(x,1,n-1)F(y,1,m-1)a[x][y] +=a[x-1][y] +a[x][y-1] - a[x-1][y-1];
	int q,x,y;	cin>>q;
	while(q--){
		cin>>x>>y;
		cout<<a[x-1][y-1]<<"\n";
		}
	return 0;
}
