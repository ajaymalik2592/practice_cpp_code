#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ALL(v) v.begin(), v.end()
int main()
{
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> vec(n), dp(n+1,0);
	for(auto &a : vec)cin >> a;
	dp[k-1] = 0;
// 	if(k != n)dp[k] = vec[k];
	for(int x =k; x<n; x++){
		if(x == k)dp[x] = dp[x-1] + vec[x];
		else dp[x] = max(dp[x-2] , dp[x-1]) + vec[x];
    }
    for(int a : dp)cout << a << "  ";
	for(int x = n-2; x>=k; x--)
	{
		if(x == n-2)dp[x] = max(dp[x], dp[x+1] + vec[x]);
		else{
		    dp[x] = max(dp[x], dp[x+1] + vec[x]);
		    dp[x] = max(dp[x], dp[x+2] + vec[x]);
		}

	}
	for(int a : dp)cout << a << "  ";

	for(int x = k-1; x>=0; x--){
	    dp[x] = dp[x+1] + vec[x];
	    if(x+2 < n){
	        dp[x] = max(dp[x] , dp[x+2] + vec[x]);
	    }
	    
	}
	for(int a : dp)cout << a << "  ";

	cout << dp[0];
}