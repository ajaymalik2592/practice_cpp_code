#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define ALL(a) (a).begin() , a.end()

int MOD = 1e9 + 7;
inline int add(int a, int b, int mod = MOD) {
  a += b; return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod = MOD) {
  a -= b; return a < 0 ? a + mod : a;
}
inline int mul(int a, int b, int mod = MOD) {
  return int((long long) a * b % mod);
}
inline int mpow(int base, long long ex, int mod = MOD) {
  int res = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) res = mul(res, base, mod);
    base = mul(base, base, mod);
  }
  return res;
}
inline int inv(int a, int mod = MOD) {
  return mpow(a, mod - 2, mod);
}
inline int mdiv(int a, int b, int mod = MOD) {
  return mul(a, mpow(b, mod - 2,  mod));
}
inline void adds(int &a, int b, int mod = MOD) {
  a += b; if (a >= mod) a -= mod;
}
inline void subs(int &a, int b, int mod = MOD) {
  a -= b; if (a < 0) a += mod;
}
inline void muls(int &a, int b, int mod = MOD) {
  a = int((long long) a * b % mod);
}
inline void mdivs(int &a, int b, int mod = MOD) {
  a = mdiv(a, b, mod);
}
vector<int> fac, ifac;
inline int ncr(int n, int r) {
  if (n < r || r < 0 || n < 0) return 0;
  return mul(fac[n], mul(ifac[n - r], ifac[r]));
}
void prepare_factorial(int nax = 1e6 + 10) {
  fac.resize(nax);
  ifac.resize(nax);
  fac[0] = 1;
  for (int i = 1; i < nax; ++i) fac[i] = mul(i, fac[i - 1]);
  ifac[nax - 1] = inv(fac[nax - 1]);
  for (int i = nax - 1; i > 0; --i) ifac[i - 1] = mul(i, ifac[i]);
}
/********************i**********************************/
void solve(){
  prepare_factorial();
  int n;
  cin >> n;
  int ans = 0;
  for(int x = 1; x<=n; x++){
    for(int y =0; y<x; y++){
      int p  = 1;
      muls(p , ncr(x-1, y));
      muls(p , fac[y]);
      muls(p , fac[n-1-y]);

      adds(ans, p);
    }
  }
  // cout << mdiv(3,2) << endl;
  cout << mul(ans, mpow(fac[n], MOD - 2));
}
/******************************************************/
int main()
{
  // cout << mul(833333341, 6) << endl;
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}