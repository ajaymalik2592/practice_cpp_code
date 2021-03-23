#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
#define fi first
#define se second
#define em emplace_back
#define pb push_back


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
int  mod = 1e9 + 7;
long long const INF = 1e18 + 42;

/*----------------------------------------------------------------------------------*/
inline int add(int a, int b){
  if(a + b >= mod)return a+ b - mod;
  return a + b;
}
inline int mul(int a, int b){
  return 1LL * a * b  % mod;
}
int sub(int a, int b){
  if(a >= b)return a - b;
  return a - b + mod;
}
int power(int a, ll b){
	if(b < 0)return 0;
  int re = 1;
  while(b){
    if(b&1){
      re = mul(re, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return re;
}
int inv(int a){
  return power(a, mod - 2);
}
/*----------------------------------------------------------------------------------*/

void solve(){
 int N = 200499;
 int count[200500], P[200500], count1[200500];
 int n; cin >> n;
 map<int,vector<int>> ma;
 // error("dads");
 // error("dads");
 for(int x = 1; x<= n; x++){
  int i;cin >> i;
  ma[i].pb(x);
 } 
  for(int x = 1; x<= n; x++){
  int i;cin >> i;
  ma[i].pb(x);
 }
 int o;cin >> o; 
  mod = o;
 // FAC();
 // error(1);
 int ans = 1;
 // for(auto a: ma){
 //  error(a.first, a.second);
 // }
 memset(count, 0, sizeof(count));
 memset(count1, 0, sizeof(count1));
 for(auto a : ma){
  map<int,int> ma1;
  for(auto g : a.second)ma1[g]++;
  for(auto b : ma1){
    count[b.second]--;
  }
  count[SZ(a.second)]++;
 }
 P[1] = 1;
 P[0] = 1;
 for(int x = 2; x<= N; x++){
 	if(P[x] == 0){
 		for(int y = x; y<=N; y += x){
 			if(P[y] == 0)P[y] = x;
 		}
 	}
 }
 // error("akakda");
 for(int x = N; x>= 2; x--){
 	count[x-1] += count[x];
 	int co = count[x];
 	count[x] = 0;
 	int x1 = x;
 	while(x1 > 1)
 	{
 		int d = P[x1];
 		while(x1 % d == 0){
 			count1[d] = add(count1[d], co);
 			x1 /= d;
 		}
 	}
 	// cout << x << " x "; 
 }
 // error("akakda");
 // for(int x =1; x<= 10; x++)cout << count1[x] << " ";
 // cout << "\npiss\n";
 for(int x = 2; x<= N; x++){
 	ans = mul(power(x, count1[x]), ans);
 }

 cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int test = 1;
  // cin >> test;
  while(test--)solve();
}