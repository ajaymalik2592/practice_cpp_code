#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
int const N = 200100;
#define fi first
#define se second
#define em emplace_back
#define ALL(a) a.begin(), a.end()
#define pb push_back
#define mk make_pair

// #define ALL(vec) begin(vec), end(vec)
typedef long long ll;
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
int const mod = 1e9 + 7;
using pii = pair<int,int>;
long long const INF = 1e18 + 42;
/*----------------------------------------------------------------------------------*/
int add(int a, int b){
  if(a + b >= mod)return a+ b - mod;
  return a + b;
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
int sub(int a, int b){
  if(a >= b)return a -b;
  return a - b + mod;
}
int fact[N], inv[N];
/*----------------------------------------------------------------------------------*/

int ncr(int a, int b){
  if(a < 0 || b < 0 || a < b)return 0;
  return mul(fact[a], mul(inv[a-b], inv[b]));
}
int ncr(pii a){
  return ncr(a.fi, a.se);
}

/* game start from here */


void solve(){
  int n, m;
  cin >> n >> m;
  int n1;
  cin >> n1;
  vector<pii> vec(n1);
  for(auto &a : vec)cin >> a.fi >> a.se;
  sort(ALL(vec), [&] (pii a, pii b){
    return a < b;
  });
  vec.pb(mk(n , m));
  map<pii, int> ma;
  auto ab  = [&](pii a, pii b){
    return mk(a.fi - b.fi + 1  + a.se - b.se,a.se - b.se );
  };
  n1++;
  for(int x =0; x<n1; x++){
    ma[vec[x]] = ncr(vec[x].fi + vec[x].se - 2, vec[x].se - 1);
    for(int y = 0; y<x; y++)
    {
      if(vec[y].se > vec[x].se)continue;
      ma[vec[x]] = sub(ma[vec[x]], mul(ncr(vec[x].fi + vec[x].se - vec[y].se - vec[y].fi , vec[x].fi - vec[y].fi), ma[vec[y]]));
    }
  }
  // for(auto a : ma){
  //   error(a.fi, a.se);
  // }
  // error(ncr(ab(mk(n, m), mk(1, 1))));
  cout << ma[mk(n, m)];


}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  fact[1] = fact[0] = 1;
  for(int x =2; x<N; x++){
    fact[x] = mul(x, fact[x-1]);
  }
  inv[N-1] = power(fact[N-1], mod - 2);
  for(int x = N-2; x>= 0; x--){
    inv[x] = mul(x+1, inv[x+1]);
  }
  // for(int x = 1; x<10; x++){
  //   error(x, fact[x], inv[x]);
  // }
  int test = 1;
  // cin >> test;
  while(test--)solve();
}