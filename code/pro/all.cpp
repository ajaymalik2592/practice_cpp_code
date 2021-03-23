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
int main()
	{
	    int t;
	    cin >> t;
	    vector<int> vec(1e4 + 5 , 1), po, pri;
	    vec[0] = vec[1] = 0;
	    for(int x =2; x<=1e4; x++)
	    {
	        for(int y =2; y<= sqrt(x); y++)
	        if(x % y == 0)vec[x] = 0;
	    }
	    for(int x =2; x<1e4; x++)if(vec[x])po.pb(x);
	    for(auto a : po)
	    {
	        if(a == 11)break;
	        int j = pow(a,a);
	        if(j > 1e4)break;
	        vec[j] = 1;
	    }
	    int dp[10004];
	    for(int x =6; x<= 1e4; x++)
	    {
	        if(vec[x])continue;
	        vec[x] = 100;
	        for(int y =2; y<=x-2; y++)vec[x] = min(vec[x], vec[x-y] + vec[y]);
	    }
		vector<int> d(100, 0);
		for(int x =2; x<1e4; x++)d[vec[x]]++;
		for(int x =1; x<10; x++)
			cout << x << " " << d[x] << "\n";
	    while(t--)
	    {
	        int n;
	        cin >> n;
	        cout << vec[n] << "\n";
	    }
		return 0;
	}
