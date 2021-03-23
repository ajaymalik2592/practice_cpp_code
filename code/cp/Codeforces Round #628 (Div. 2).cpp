#include<bits/stdc++.h>

using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
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
int mod = 1e9 + 7;

int add(int a, int b){
	if(a + b >= mod)return a+ b - mod;
	return a + b;
}
int mul(int a, int b){
	return 1LL * a * b  % mod;
}
int power(int a, int b){
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
// int const N = 100000 + 5;
// int fact[N], inverse[N];
// void FAC(){
//  	fact[0] = 1;
// 	for(int x = 1; x< N; x++){
// 		fact[x] = mul(fact[x-1], x);
// 	}
// 	inverse[N-1] = power(fact[N-1], mod -2);
// 	for(int x = N-2; x>= 0; x--){
// 		inverse[x] = mul(x + 1, inverse[x+1]);
// 	}

//  }

// int ncr(int a, int b){
// 	if(a < b)return 0;
// 	return mul(fact[a], mul(inverse[a-b], inverse[b]));
// }


/******************************************************/

void solve(){
	ll a;
	cin >> a;
	for(int x = 1; x*x <= a ; x++){
		if(a % x == 0){
			int left = a / x;
			if(x > 1){
				cout << left << " " << left * (x- 1) << "\n";
				return;
			}
			if(left > 1){
				cout << x << " " << (left - 1) * x << "\n";
				return;
			}
		}
	}
	cout << 1 << " " << (a-1) << "\n";
}


/******************************************************/
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	t = 1;
	cin >> t;
	while(t--){
		solve();
	}

}
