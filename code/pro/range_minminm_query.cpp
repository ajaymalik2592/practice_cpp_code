#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	cin >> n;
	vector<int> vec(n), v(n);
	for(int x =0; x<n; x++)scanf("%d", &vec[x]);
	int m;
	long long su = 0;
	int x1, y1 ;
	cin >> m >> x1 >> y1;
	int t , u, v1;
	int dp[n][18];
	for(int x =0; x<n; x++)
		dp[x][0] = vec[x];
	v[n-1] = vec[n-1];
	for(int s = n-2; s>=0; s--)v[s] = max(v[s+1], vec[s]);
	int post[20];
	int g = 1;
	for(int x =0; x<20 ; x++)
		post[x] = g, g*=2;
	for(int x =1; x<= 17; x++)
		for(int y =0; y<n; y++)
			if(y + post[x] < n)
				dp[y][x] = max(dp[y][x-1], dp[y+post[x-1]][x-1]);
			else
				dp[y][x] = v[y];
	// for(int x =0; x<n; x++)
	// {
	// 	cout << "check " << x << endl;
	// 	for(int y =0; y<n; y++)
	// 		cout << dp[x][y ] << " ";
	// 	cout << endl;
	// }
	vector<int> pop(n+11), xx1(n+15), yy1(n+15);
	pop[0] = 0;
	xx1[0] =0, yy1[0] = 0;
	for(int x = 1; x<n+15; x++)
		xx1[x] = x % (n-1), yy1[x] = x % n, pop[x] = log2(x);

	
	for(int x =0; x<m; x++)
	{
		u =x1, v1 = y1;
		if(u > v1)swap(u,v1);

		g = pop[v1-u+1];
		su += max(dp[u][g], dp[v1-post[g] +1][g]);
		x1 = xx1[x1+7];
		y1 = yy1[y1+11];
		// cout << x << " " << su << endl;
	}
	cout << su;

}