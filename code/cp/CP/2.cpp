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
int const N =  10000;

/********************i**********************************/
vector<int> pr(6e6 + 10000), p;
void sieve(){
  for(int x = 2; x<N; x++){
    if(pr[x] == 0){
      p.push_back(x);
      for(int y = x + x; y<N; y+=x)pr[y] = 1;
    }
  }
}
void solve(){
  int n, k, l;
  cin >> n >> k >> l;
  set<int> se;
  for(int v = 0; v<n; v++){
    int i;cin >> i;
    se.insert(i);
  }
  vector<int> vec;
  for(auto b : se)vec.pb(b);
  set<int> need;
  n = vec.size();
  for(int x = 0; x<n; x++){
    for(int y = x+1; y<n; y++){
      int u = __gcd(vec[x], vec[y]);
      if(se.find(u) == se.end())need.insert(u);
    }
  }

  for(auto b : need)cout << b << " ";  
}


/******************************************************/
int main()
{
  // sieve();
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int tt;
  tt = 1;
  cin >> tt;
  while(tt--){
    solve();
  }
}