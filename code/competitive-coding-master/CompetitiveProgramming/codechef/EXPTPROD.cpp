/**
 * Consider the frequency array of the numbers, when all possible choices
 * in K moves are completed.
 * Notice that we can merge 2 freq arrays of steps A, and steps B, in O(n^2)
 * to get the freq array of steps A + B.
 * Now, we can use binary exponentiation to calculate freq array of K steps,
 * in O(n^2 log K).
 * the "merge" part is done by function "op"
 * exponentiation is function "go"
**/
#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) (vec).begin(),(vec).end()
typedef long long i64;
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
void err(istream_iterator<string>) {}
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << endl; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18;
/***********************************************************************/
inline int add(int a, int b, int mod = MOD) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int sub(int a, int b, int mod = MOD) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline int mul(int a, int b, int mod = MOD) {
  return int((long long) a * b % mod);
}
inline int mpow(int base, long long ex, int mod = MOD) {
  int res = 1;
  while (ex > 0) {
    if (ex & 1) res = mul(res, base, mod);
    base = mul(base, base, mod);
    ex >>= 1;
  }
  return res;
}
inline int inv(int a, int mod = MOD) {
  return mpow(a, mod - 2, mod);
}
auto op(const vector<int> &a, const vector<int> &b) {
  int n = SZ(a);
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      const int k = (i * j) % n;
      res[k] = add(res[k], mul(a[i], b[j]));
    }
  }
  return res;
}
auto go(int k, const vector<int> &a) {
  if (k == 1) return a;
  if (k & 1) return op(a, go(k - 1, a));
  return go(k >> 1, op(a, a));
}
int32_t main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      a[x]++;
    }
    a = go(k, a);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      ans = add(ans, mul(i, a[i]));
    }
    ans = mul(ans, inv(mpow(n, k)));
    cout << ans << '\n';
  }
  
  return 0;
}
