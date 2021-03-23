#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
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


/////////////////////////////////////////////////

struct rect{
    int tx, ty, bx, by;
    bool operator < (rect &b){
        if(by != b.by)return by < b.by;
        if(ty != b.ty) return ty > b.ty;
        if(tx != b.tx)return tx < b.tx;
        if(bx != b.bx)return bx > b.bx;
        return true;
    }
    bool overlap(rect &b){
        bool over = false;
        int x1 = tx, y1 = ty;
        if(ty >= b.by &&( (tx >= b.tx && tx <= b.bx)  || (bx >= b.tx && bx<= b.bx) || (tx <= b.tx && bx >= b.bx) ) )over = true;
        return over;
    }
};typedef struct rect rect;
int visited[1001];
vector<int> edge[1001];
vector<rect> vec(1001);
int L , X, R;

void dfs(int node){
  if(visited[node] == 0){
    // error(L, R);
    visited[node] =1;
    X = min(X, vec[node].bx);
    L = min(L, vec[node].tx);
    R = max(R, vec[node].bx);
    // error(L, R);
    for(auto a : edge[node]){
        dfs(a);
    }
  }
}
int main()
  {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int t;
      cin >> t;
      while(t--){
          int n, w , l; 
          cin >> n >> w >> l;
          for(int x = 0; x<n ; x++)cin >> vec[x].tx >> vec[x].ty >> vec[x].bx >> vec[x].by;
         
          sort(vec.begin(), vec.begin() + n );
        //     for(auto a : vec){
        //      error(a.tx);
        //      error(a.ty);
        //      error(a.bx);
        //      error(a.by);
        //   }
          for(int x = 0; x<n; x++){
            for(int y = x +1 ; y<n; y++){
              if(vec[x].overlap(vec[y]) ){
                edge[x].pb(y);
                edge[y].pb(x);
              }
            }
          }
          // for(int x = 0; x<n; x++){
          //   cout << "connection of "  << x << "  ----  ";
          //   for(auto a : edge[x])cout << a << " ";
          //   cout << endl;

          // }
          int ans = 0;
          for(int x =0; x<n; x++){
            if(visited[x] == 0){
              // cout << x << " dfs  " << endl;
              L = w;
              X  = L;
              R = 0;
              dfs(x);
              // cout << "L " << L << " " << "R " << R << endl;
              if(L <= 0 && R >= w )ans++;
              // if(l == 0 && X != 0 && R >= w)ans++;
              
            }
          }
          cout <<  ans << '\n';
          for(int x = 0; x<n; x++){
              edge[x].clear();
              visited[x] = 0;
          }
      }
    return 0;
  }
