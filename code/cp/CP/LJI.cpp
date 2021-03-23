#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define fi first
#define se second
#define em emplace_back
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define mk make_pair
typedef long long ll;
using pii = pair<int,int>;

template<typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template<typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}
template<typename A> string to_string(A v) {bool f = false; string r = "{"; 
  for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) {string r; 
  for (auto x: v) r += "\n" + to_string(x); return r;}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
/*----------------------------------------------------------------------------------*/
int  mod = 1e9 + 7;
int const N = 1000 * 11000;
typedef long long i64;
i64 INF = 1e18, NIN = -1 * INF;

/******************************/

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


int fact[N], inv[N];

int ncr(int a, int b){
  if(a < 0 || b < 0 || a < b)return 0;
  return mul(fact[a], mul(inv[a-b], inv[b]));
}
int ncr(pii a){
  return ncr(a.fi, a.se);
}
void fac(){
  fact[1] = fact[0] = 1;
  for(int x =2; x<N; x++){
    fact[x] = mul(x, fact[x-1]);
  }
  inv[N-1] = power(fact[N-1], mod - 2);
  for(int x = N-2; x>= 0; x--){
    inv[x] = mul(x+1, inv[x+1]);
  }
}
// vector<int> v[N], ans(N, 0), parent(N), si(N);
// void dfs(int a, int p){
//  parent[a] = p;
//  si[a] = 0;
//  for(int x : v[a]){
//   if(x == p)continue;
//   dfs(x, a);
//   si[a] ++;
//  }
//  for(int x : v[a]){
//   if(p == x)continue;
//   ans[a] =add(ans[a],mul(si[a], ans[x]));
//  }
//  if(si[a] == 0)ans[a] = 1;

void solve(){
 ll a, b;
 cin >> a >> b;
 int bit = max(__lg(a), __lg(b));
 int ans = 0;
 ll total = a ^ b;
 for(int x = 1; x<= bit; x++){
  if(b & 1)b = (1LL << bit) + (b>>1);
  else b >>= 1;
  ll ans1 = a ^ b;
  if(total < ans1)total = ans1, ans = x;
 }
 cout << ans << " " << total << "\n";
}

int32_t main() {

  // fac();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int test = 1;
  cin >> test;
  while(test--)solve();
}