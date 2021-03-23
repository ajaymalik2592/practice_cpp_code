#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
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
int const N = 1000001;
#define fi first
#define se second
#define em emplace_back
#define ALL(a) a.begin(), a.end()
/*----------------------------------------------------------------------------------*/
long long pollards_p_minus_1(long long n) {
    int B = 10;
    long long g = 1;
    while (B <= 1000000 && g < n) {
        long long a = 2 + rand() %  (n - 3);
        g = __gcd(a, n);
        if (g > 1)
            return g;

        // compute a^M
        for (int p : primes) {
            if (p >= B)
                continue;
            long long p_power = 1;
            while (p_power * p <= B)
                p_power *= p;
            a = power(a, p_power, n);

            g = gcd(a - 1, n);
            if (g > 1 && g < n)
                return g;
        }
        B *= 2;
    }
    return 1;
}
void solve(){
 ll a, b;cin >> a >> b;
 if(pollards_p_minus_1(a)){
  cout << "COOL\n";
 }
 else{
  cout << "NOT COOL\n";
 }
 
}

int32_t main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test = 1;
  cin >> test;
  while(test--)solve();
}