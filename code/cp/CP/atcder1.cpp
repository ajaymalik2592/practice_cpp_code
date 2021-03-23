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
int const N = 200100;
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
ll pow(ll a, int b){
  ll r = 1;
  while(b){
    if(b&1)r *= a;
    a *= a;
    b >>= 1;
  }
  return r;
}
ll pope(multiset<ll> se){
  // error(se);
  ll n = se.size();
  ll ans = 0, p = pow(10ULL, n-1);
  for(ll x : se){
    ans += p * x;
    p /=10;
  }
  // error(ans);
  return ans;
}
void solve(){
 ll a, b;
 cin >> a >> b;
 multiset<ll> se;
 while(a > 0){
  se.insert(a%10);
  a /= 10;
 }

 ll n = se.size();
 ll ans = 0;
 for(int xx = n-1; xx>=0; xx--){
  ll o = 0;
  // error(se);
  multiset<ll> s (se.begin(), se.end());
  for(ll x : se){
    // error(s);
    ll t = ans +  pow(10LL, xx) * x;
    ll poye = pow(10LL, xx) * x;
    // error(ans, poye);
    s.erase(s.find(x));
    // error(t);
    t += pope(s);
    s.insert(x);
    if(t <= b )o = x;
    // error(t, b);

  }
  error(o);
  se.erase(se.find(o));
  cout << o;
  ll fuck = pow(10LL, xx) * o ;
  // error(ans, "okks" , " 1 ", fuck);
  ans += fuck;
  // error(ans, "okks", " 2 ");
 }


}

int32_t main() {
  // cout << pow(10LL, 6) * 9 << endl;
  // cout << pow(10ULL, 6) * 9 << endl;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  // cin >> test;
  for(int x = 1; x<= test; x++)
  {
    // cout << "Case #" << x << ": ";
    solve();
  }
}