/**
 * Let the given matrix represent matrix of a graph.
 * Now, there is atleast one such nde that has a self loop.
 * So, given an arbitrary big k, we have to check if we can reach
 * every vertex from every vertex. We can "waste" as many steps as we like 
 * in the self loop.
 * So, we just need to check if a node can reach every node,
 * and is reachable from every node.
 * Equivalently, we check if the graph is a scc. 
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
vector<vector<int>> adj;
vector<int> vis;
int n, cnt;
void dfs(int u) {
  vis[u] = 1;
  cnt++;
  for (int v = 0; v < n; ++v) if (adj[u][v]) {
    if (!vis[v]) dfs(v);
  }
}
int32_t main() {
 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  cin >> n;
  adj.assign(n, vector<int>(n));
  for (auto &v : adj) for (int &z : v) cin >> z;
  vis.assign(n, 0);
  cnt = 0; dfs(0);
  if (cnt < n) kek("NO");
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      swap(adj[i][j], adj[j][i]);
    }
  }
  vis.assign(n, 0);
  cnt = 0; dfs(0);
  if (cnt < n) kek("NO");
  kek("YES");
  
  return 0;
}
