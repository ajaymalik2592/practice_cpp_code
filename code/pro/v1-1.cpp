#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back

int main()
	{	ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n,k;
		string s;
		cin>>n>>k>>s;
		int count[26][n],par[26];
		F(x,0,25)par[x] = 0;
		F(x,0,25) F(y,0,n-1)count[x][y]=0;
		char e;
		e = (char)s[0]- 'a';
		count[e][0]++;
		if(k==1)par[e] ++ , count[e][0] = 0;
		
		F(x,1,n-1)
		{ e =(char)s[x]- 'a';
			count[e][x] = count[e][x-1] + 1;
			if(count[e][x] == k)count[e][x] = 0 , par[e]++;
			//cout<<"  "<<e<<" "par[e]
			}
			int su = 0;
		F(x,0,25)su = max(su , par[x]);
		cout<<su<<"\n";
		
		return 0;
	}
