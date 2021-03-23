#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
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
int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18 + 42;
/***********************************************************************/
ll fun(vector<ll> vec, int n){
  if(n == 1){
    return  0 ;
  }
  ll dp[n][2]; // dp[x][1] -> dish have been serverd as per his choice
  dp[0][0] = vec[0];
  dp[0][1] = vec[0];
  for(int x = 1; x<n; x++){  
    dp[x][1] = min( dp[x-1][1] , dp[x-1][0]) + vec[x];
    dp[x][0] = dp[x-1][1];
  }
  // ll ans = dp[n-1][0];
  // for(int x = n-2; x>=1; x--){
  //   if(ans == min(dp[x-1][0], dp[x-1][1]) + vec[x])    ans -= vec[x];
  //   // error(x, ans);
  // }

  return min(dp[n-1][1] ,dp[n-1][0]);

}


void solve_case(){
  int n; cin >> n;
  vector<ll> a(n); for(auto &a1 : a)cin >> a1;
  ll ans = fun(a, n);
  // error(a);
  for(int x = 0; x<(n)/2; x++){
    swap(a[x], a[n-x]);
  }
  // error(a);
  cout << min(ans , fun(a, n));
}


/**************/


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int tt = 1;
  //~ cin >> tt;
  while (tt--) {
    solve_case();
  } 
}
