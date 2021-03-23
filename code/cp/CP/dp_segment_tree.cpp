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
/*----------------------------------------------------------------------------------*/
typedef long long i64;
i64 INF = 1e18, NIN = -1 * INF;
struct Node {
  i64 minv, lz;
  Node(): minv(), lz() {}
  friend Node operator + (const Node &lhs, const Node &rhs) {
    Node node;
    node.minv = max(lhs.minv, rhs.minv);
    return node;
  }
  //~ friend ostream &operator << (ostream &os, const Node &p) {
    //~ return os << "<" << p.minv << ", " << p.lz << ">";
  //~ }
};
struct SegTree {
  #define li (i + i)
  #define ri (i + i + 1)
  vector<int> ss, ee;
  vector<Node> t;
  int n;
  SegTree(int n1): ss(n1 << 2), ee(n1 << 2), t(n1 << 2) {
    n = n1;
    build(1, 1, n1);
    for(int x = 0; x< (n<<2); x++)t[x].minv = 0;
  }
  void build(int i, int l, int r) {
    ss[i] = l, ee[i] = r;
    if (l == r) { return; }
    int m = (l + r) >> 1;
    build(li, l, m); build(ri, m + 1, r);
  }
  inline void push(int i) {
    i64 &lz = t[i].lz;
    if (lz == 0) { return; }
    i64 len = ee[i] - ss[i] + 1;
    t[i].minv += lz;
    if (len > 1) {
      t[li].lz += lz;
      t[ri].lz += lz;
    }
    lz = 0;
  }
  inline void update(int i, int us, int ue, i64 a) {
    if (us <= ss[i] && ee[i] <= ue) {
      t[i].lz += a;
      push(i); return;
    }
    push(i);
    if (ue < ss[i] || ee[i] < us) { return; }
    update(li, us, ue, a); update(ri, us, ue, a);
    t[i] = t[li] + t[ri];
  }
  inline Node ask(int i, int qs, int qe) {
    push(i);
    if (qs == ss[i] && qe == ee[i]) { return t[i]; }
    if (qe <= ee[li]) { return ask(li, qs, qe); }
    if (qs >= ss[ri]) { return ask(ri, qs, qe); }
    return ask(li, qs, ee[li]) +
      ask(ri, ss[ri], qe);
  }
  void update(int L, int R, i64 val) {
    return update(1, L, R, val);
  }
  i64 ask(int L, int R) {
    if(L > n)return 0LL;
    return  ask(1, L, R).minv;
  }
  #undef li
  #undef ri
  //~ void debug(int i = 1) {
    //~ auto nn = make_pair(make_pair(ss[i], ee[i]), t[i]);
    //~ error(nn);
    //~ if (ss[i] == ee[i]) { return; }
    //~ debug(li); debug(ri);
  //~ }
};

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

void solve(){
 
}

int32_t main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);  int test = 1;
  // cin >> test;
  while(test--)solve();
}