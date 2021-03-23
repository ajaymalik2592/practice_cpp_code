#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
void CountPS(char str[], int n) 
{ 
	long long Q, L, R, X, Y, M;
	cin >> Q >> L >> R >> X >> Y >> M;

    int dp[n][n]; 
    memset(dp, 0, sizeof(dp)); 
  
    bool P[n][n]; 
    memset(P, false , sizeof(P)); 
  
    for (int i= 0; i< n; i++) 
        P[i][i] = true; 
  
    
    for (int i=0; i<n-1; i++) 
    { 
        if (str[i] == str[i+1]) 
        { 
            P[i][i+1] = true; 
            dp[i][i+1] = 1 ; 
        } 
    } 
 
    for (int gap=2 ; gap<n; gap++) 
    { 
        // Pick starting point for current gap 
        for (int i=0; i<n-gap; i++) 
        { 
            // Set ending point 
            int j = gap + i; 
  
            // If current string is palindrome 
            if (str[i] == str[j] && P[i+1][j-1] ) 
                P[i][j] = true; 
  
            if (P[i][j] == true) 
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1]; 
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; 
        } 
    } 
  	vector<int> vec[n+1];

	for(int x =0; x<=n; x++)vec[x].pb(0);
  	for(int x =1; x<=n; x++)vec[1].pb(x);
  	int j = 0;
  	for(int x = 2; x<=n; x++)
  	{	j = 0;
  		for(int y = 0; y<= n-x; y++)
  			j += p[y][y+x-1], vec[x].pb(j);
  	}
  	
    long long sum = 0;
    while(q--)
    {
    	
    	L = (L + ans)%M;
    	R = (R + ans) %M;
    	X = (X + ans) % M;
    	Y = (Y + ans) % M;
    	if(L  > R)swap(L, R);
    	if( X > Y)swap(X, Y);
    }
} 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	{
		string s;
		cin >> s;
		CountPS(s, s.length());
	}
}