#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define mk make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
string int_str(int a)
{
	string s = "";
	while(a)
	{
		s += char ('0' + a % 10 );
		a /= 10;
	}
	reverse(ALL(s));
	return s;
}
int main()
{
	speed
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<ll> vec1(n,0);
		for(auto &g : vec1) cin >> g;
		if(n == 1)
		{
			cout << max(vec1[0], 0LL) << endl;
			continue ;
		}
		ll re = 0;
		ll dp[n+1][2];
		dp[1][0]= 0, dp[1][1] = vec1[0];
		int check = 0,vis[n+1];
		for(int x =1;x < n ; x++)
		{
			dp[x+1][0] = dp[x][1];
			dp[x+1][1] = max(dp[x][0] + vec1[x] , dp[x][1]);
			if(vec1[x] < 0)
				{vis[x +1 ] = 0;continue;}
			if(dp[x][0] + vec1[x] >= dp[x][1]) vis[x+1] = 1, vis[x]= 0;
			else vis[x+1] = 0, vis[x] = 1;
		}
		string st = "";
		if(dp[n][1] == dp[n-1][1] && vec1[n-2] > vec1[n-1])
			vis[n] =0, vis[n-1] = 1;
		for(int x =n; x>0; x--)
		{	
			if(vis[x])
			st += int_str(vec1[x-1]);
			cout << x <<"  " <<  st << endl; 
		}

		cout << st << endl;
	}
}