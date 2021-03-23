#include<bits/stdc++.h>
using namespace std;
long long dp[450][450];
int n;
long long fun(int a,int  b)
{
	if(a == b)return 1;
	else return 2;
}
int main()
{
		
	cin >> n;
	vector<long long > vec(n);
	long long po = 0;
	for(auto &a : vec)
		cin >> a, po += a;
	
	for(int x =0; x<n; x++)
	{
		for(int y =0; y<n; y++)
			dp[x][y] = 3e18;
	}
	for(int x =0; x<n; x++)
		dp[x][x] = vec[x];
	long long result = 3e18;
	for(int x = 1; x<n; x++)
	{
		for(int y = 0; y<n; y++)
		{
			
			for(int z= 0; z<x; z++)
			{
				dp[y][(y+x) % n] = min(dp[y][(z+y)%n]  + dp[(y+z+1)%n][(x+y) % n] , dp[y][(y+x)%n] );
			 }
			
			long long h = 0;
			if(y +x < n)
			{
				for(int g = y; g<= x + y; g++)
					h+= vec[g];
			}
			else
			{
				for(int g = y; g<= n-1; g++)
					h+= vec[g];
				for(int g = 0; g<= (x + y)%n; g++)
					h+= vec[g];
			}
			dp[y][(y+x)%n] += h ;

		}
	}
	result = dp[0][n-1];
	for(int x =1; x<n; x++)
	{
		result = min(result, dp[x][x-1] );
    }
	
	cout << result - po << "\n";
	
}
