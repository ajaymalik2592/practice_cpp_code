#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
typedef long long ll;
#define pb push_back
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
long long const INF = 1e9 + 100 ;
/***********************************************************************/

void solve_case() {
  int n;
  cin >> n;
  vector<int> arr(1e5 + 5, 500), left(1e5 +5 , 0), right(1e5 + 5 , 1e5);
  for(int x =0; x<n; x++){
    int i, j;
    cin >> i >> j;
    arr[i] = min(arr[i], j);
  }
  stack<int> sta;
  for(int x =1; x<=1e5; x++){
    while(sta.size() > 0 && arr[sta.top()] >= arr[x])sta.pop();
    if(sta.size() != 0)left[x] = sta.top();
    sta.push(x);
  }

  while(!sta.empty())sta.pop();
  for(int x =1e5; x>= 1; x--){
    while(sta.size() > 0 && arr[sta.top()] >= arr[x])sta.pop();
    if(sta.size() != 0)right[x] = sta.top();
    sta.push(x);
  }

  int ans = 0;
  // for(int x = 1; x<= 10; x++){
  //   error(x, left[x] , right[x]);
  // }
  for(int x = 1; x<= 1e5; x++){
    ans = max(ans, arr[x] * (right[x] - left[x] ));
  }
  cout << ans;
}
int32_t main() {
  cin.tie(nullptr) -> sync_with_stdio(false);
  
  // int tt; tt = 1;
  // while (tt--) solve_case();
  enum {o = -1, m, p = 5};
  printf("%d", m);
}
