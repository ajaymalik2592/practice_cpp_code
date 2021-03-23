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
#define pb push_back
//pointer remove only single occurance while key remove all the matched occurances
/***********************************************************************/
vector<int> matrix[205], id(205), seen(205);
int identity = 0;
void dfs(int a){
  id[a] = identity;
  // error(a);
  seen[a] = 1;
  for(auto b : matrix[a])
  {
    if(seen[b] == 0){
      dfs(b);
    }
  }
}
void solve_case(){
 int s, l ,n;
 cin >> s >> l >> n;
 map<string, int> ma;
 map<int, string> ma1;
 set<string> se;
 int in = 0;
 for(int i = 0; i<s; i++){
  string s; cin >> s;
  se.insert(s);
 }
 bool check[s+5][s+5];
 memset(check, 0 , sizeof(check));
 for(auto a: se)ma[a] = in++;
 for(int x = 0; x<l; x++){
  string a, b;cin >> a >> b;
  // matrix[ma[a]].pb(ma[b]);
  // matrix[ma[b]].pb(ma[a]);
  check[ma[a]][ma[b]] = check[ma[b]][ma[a]] = 1;
 }
 // for(int x = 0; x<s; x++){
 //  for(int y = 0 ;y<s; y++){
 //    cout << check[x][y] << " ";
 //  }
 //  cout << endl;
 // }
 // for(int x = 0; x<s; x++){
 //  if(seen[x] == 0){
 //    dfs(x);
 //    identity++;
 //  }
 // }
 multiset<string>sett;
 for(int x =0; x<n; x++){
  string s;cin >> s;
  // error(sett);
  if(sett.size() == 0){
    sett.insert(s);
  }
  else{
    string h = *sett.rbegin();
    if(check[ma[h]][ma[s]] == 1){
      sett.insert(s);
    }
    else{
      for(auto a : sett)cout << a << " ";
      sett.clear();
      sett.insert(s);
    }
  }
 }
 for(auto a : sett)cout << a << " ";
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
