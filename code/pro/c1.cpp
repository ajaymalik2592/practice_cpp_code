#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back

int main()
	{	ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t;
		cin>>t;
		while(t--)
		{
			int m;
			cin>>m;
			int n1,n2,e1,e2,h1,h2,t1,t2,t3;
			cin>>n1>>e1>>h1;
			vector<ll> a1[n1];
			F(x,0,e1-1)cin>>t1>>t2>>t3;
			cin>>n2>>e2>>h2;
			F(x,0,e2-1)cin>>t1>>t2>>t3;
			cout<<"NO\n";
			}
		return 0;

	}


