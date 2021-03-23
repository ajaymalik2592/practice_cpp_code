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
 int n, q;
 cin >> n >> q;
 int ans = 1;
 vector<int> fac;
 int n1 = n;
 for(int x = 2; x*x <= n; x++){
   if(n1 < x)break;
   if(n1 % x == 0){
    if(x*x == n1)fac.pb(x);
    else{
      fac.pb(x);
      fac.pb(n / x);
    }
   }
   while(n1 % x == 0 && n1 >  1)n1 /= x;
 }
 if(n1 > 1)fac.pb(n1);
 sort(ALL(fac));
 reverse(ALL(fac));
 bool flag = true;
 for(auto a : fac){
  if(a == n)continue;
  cout << "? " << a << '\n';
  int u;
  cin >> u;
  if(u != 0 && a % u == 0){
    ans = max(n / a , ans);
  }
  else{
    flag = false;
    ans = 1;
    break;
  }
 }
 cout << '!' << " " << (flag ? ans : 1)<< endl;
 int i;
 cin >> i;
}

/**************/
int fun(string s){
  int x = 0;
  int n = s.length();
  for(int x =0; x<n; x++){
    if(s[x] >= '0' && s[x] <= '9'){
      x = x * 10 + s[x] - '0';
    }
  }
  return x % 2;
}

int32_t main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
 
  // int tt = 1;
  // cin >> tt;
  // while (tt--) {
  //   solve_case();
  // } 
  vector<string> ajay =  {  "Food","Attire" ,"Decorationandsignage", "misc"};
  cout << "Image,Class\n";

  for(int x =1;x <=3219; x++){
    string s;
    cin >> s;
    int M = 1e3 + 1;
    cout << s << "," << ajay[0] << "\n"; 
  }
}


