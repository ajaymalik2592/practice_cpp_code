#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define ALL(a) (a).begin() , a.end()
typedef long long ll;

int mod = 1e9 + 7;

int add(int a, int b){
  if(a + b >= mod)return a+ b - mod;
  return a + b;
}
int sub(int a, int b){
  if(a >= b)return a - b;
  return a - b + mod;
}
int mul(int a, int b){
  return 1LL * a * b  % mod;
}
int power(int a, int b){
  int re = 1;
  while(b){
    if(b&1)re= mul(re, a);
    a = mul(a, a);
    b>>=1;
  }
  return re;
}
int const N = 100 *1001 + 49;

/********************i**********************************/

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> vec(n, vector<ll> (m)), dp(n+1, vector<ll>(m+1)), edge(n+1, vector<ll>(m+1, 0));
  for(auto &a : vec)for(auto &b : a)cin >> b;
  for(int x = 1; x<=n; x++){
    for(int y = 1; y<=m; y++){
      dp[x][y] = min(dp[x-1][y], dp[x][y-1]) + vec[x-1][y-1];
      if(dp[x][y] == dp[x-1][y] + vec[x-1][y-1])edge[x-1][y] = 1;
      if(dp[x][y] == dp[x][y-1] + vec[x-1][y-1])edge[x][y-1] = 1;
    }
  }
  edge[n][m] =1;
  // for(int y = m-1; y>=1; y--){
  //   if(dp[n][y] + vec[n-1][y-1] == dp[n][y+1]){
  //     edge[n][y] = 1;
  //   }
  //   else{
  //     break;
  //   }
  // }
  // for(int x = n-1; x>=1; x--){
  //   for(int y = m; y>=1; y--)
  //   {
  //     if(dp[x][y] == dp[x+1][y] + vec[x][y] && edge[x][y])
  //   }
  // }
  

}


/******************************************************/
int main()
{
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int tt;
  tt = 1;
  cin >> tt;
  while(tt--){
    solve();
  }
}