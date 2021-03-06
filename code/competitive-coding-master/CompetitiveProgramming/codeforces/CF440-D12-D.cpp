/**
 * let dp[u][k], be the minimum answer when taking a subtree rooted at u, and of size k
 * Answer for each node can be done in O(k * k * no. of children)
 * To reconstruct the answer, keep links to the states from which answer is 
 * minimized, and reconstruct answer recursively.
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
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18;
/***********************************************************************/

int32_t main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  vector<pair<int,int>> edges;
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v; --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.emplace_back(u, v);
  }
  int opt = MOD;
  vector<int> ans;
  vector<int> sizes(n);
  vector<vector<int>> dp(n, vector<int>(n + 1, MOD));
  vector<vector<vector<pair<int,int>>>> links(n);
  function<vector<int>(int,int)> get = [&] (int u, int sz) {
    int t = SZ(links[u]) - 1;
    vector<int> res = {u};
    while (t >= 0) {
      if (links[u][t][sz].first != -1) {
        auto his = get(links[u][t][sz].first, links[u][t][sz].second);
        for (const int &v : his) {
          res.push_back(v);
        }
        sz -= links[u][t][sz].second;
      }
      --t;
    }
    assert (sz == 1);
    return res;
  };
  function<void(int,int)> dfs = [&] (int u, int p) {
    sizes[u] = 1;
    dp[u][1] = SZ(g[u]) - 1 + (p == -1);
    for (const auto &v : g[u]) if (v != p) {
      dfs(v, u);
      sizes[u] += sizes[v];
      auto pre = dp[u];
      vector<pair<int,int>> link(n + 1, make_pair(-1, -1));
      for (int i = 1; i <= sizes[v]; ++i) {
        for (int j = 1; j + i <= sizes[u]; ++j) {
          if (uin(dp[u][j + i], dp[v][i] + pre[j] - 1)) {
            link[j + i] = {v, i};
          }
        }
      }
      links[u].push_back(move(link));
    }
    if (uin(opt, dp[u][k] + (p != -1))) {
      ans = get(u, k);
    }
  };
  dfs(0, -1);
  cout << opt << '\n';
  sort(ALL(ans));
  for (int i = 0; i < n - 1; ++i) {
    if (binary_search(ALL(ans), edges[i].first) ^ binary_search(ALL(ans), edges[i].second)) {
      cout << i + 1 << ' ';
    }
  }
  cout << '\n';
  
  return 0;
}
