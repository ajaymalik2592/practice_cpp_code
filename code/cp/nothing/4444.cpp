#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
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
int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18 + 42;
/***********************************************************************/
int good(auto &a) {
  if (SZ(a) <= 2) return 1;
  i64 d = a[1] - a[0];
  for (int i = 2; i < SZ(a); ++i) {
    if (a[i] - a[i - 1] != d) return 0;
  }
  return 1;
}
bool fun(int i, int j, auto &a){
	vector<int> ind(a.size(), 0);
		// vector<int> ind(n, 0);
	// 0, 1
	ind[i] = ind[j] = 1;
	int d = a[1] - a[0];
	int last = a[j];
	multiset<int> se;
	se.insert(a[i]);
	se.insert(a[j]);
	int i = 2;
	for(int x = 0; x<n; x++){
		if(ind[x] == 1)continue;
		if(a[x] - last == d){
			ind[x] = 1;
			last = a[x];
			se.insert(a[x]);
			i++;
		}
	}
	if(i >= s.size() -2)return true;

	int i1 = -1, i2 = -1;
	for(int x = 0; x<n; x++){
		if(ind[x] == 0){
			ind[x] = 1;
			if(i1 == -1)i1 = x;
			else
			{
				i2 = x;
				ind[x] = x;
				break;
			}
		}
	}
	vector<int> v = {a[i1] , a[i2]};
	last = a[i2];
	d = a[i2 ] - a[i1];
	for(int x = i2+1; x<n; x++){
		if(ind[x] == 1)continue;
		if(a[x] - last == d){
			ind[x] = 1;
			last = a[x];
			v.push_back(a[x]);
		}
	}
	if(good(v))



}
int solve_case() {
  int n; cin >> n;
  vector<i64> a(n);
  for (auto &x : a) cin >> x;
  sort(ALL(a));
  if (n <= 2) return 1;
  bool flag = false;
	flag |= fun(0,1,a);	
	flag |= fun(1,2,a);	
	flag |= fun(0, 2,a);
	if(flag)return 1;	

  return 0;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
  int tt = 1;
  //~ cin >> tt;
  while (tt--) {
    cout << (solve_case() ? "Yes\n" : "No\n");
  } 
}
