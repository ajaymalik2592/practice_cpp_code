#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;i<n;i++)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define ss(s) scanf("%s",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pll;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pll>   vpll;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
const int mod = 1000000007;
const int N = 1005;
vi g[N];
const int LG = 12;
//LCA begins
//1 based index
int a[N], lvl[N], P[N][LG];
void dfs(int u, int par){
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
  for(int v:g[u]){
    if (v == par) continue;
    dfs(v, u);
  }
}

int lca(int u, int v){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);

    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }

    if (u == v) 
      return u;

    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}

// //Get the ancestor of node "u"
// //which is "dis" distance above.
// int getAncestor(int u, int dis){
//     dis = lvl[u] - dis;
//     int i, lg = 0;
//     for(; (1<<lg) <= lvl[u]; lg++); lg--;

//     for(i=lg; i>=0; i--){
//         if (lvl[u] - (1<<i) >= dis)
//             u = P[u][i];
//     }

//     return u;
// }

// //returns the distance between
// //two nodes "u" and "v".
// int dis(int u, int v){
//     if (lvl[u] < lvl[v]) swap(u, v);
//     int w = lca(u, v);
//     return lvl[u] + lvl[v] - 2*lvl[w];
// }
struct  data
{
  int i, j, a;
};
vector<int> val(1005);
bool cmp(int a, int b){
  if(val[a] != val[b])return val[a] > val[b];
  return a < b;
}
int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int i, n, q, m, j;
  int u, v;
  cin >> n ;
  fo(i, n-1){
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
  }
  vector<int> vec(n);
  iota(vec.begin(), vec.end(), 1);
  vector<data> vec1(n/2);
  for(int x =1; x<=n; x++){
    if(g[x].size() == 1)val[x] = 1;
  }
  sort(vec.begin(), vec.end() , cmp);
  for(int x =0; x<n/2; x++){
    vec1[x].i = vec[x*2];
    vec1[x].j = vec[x*2 + 1];
    cout << "? " << vec1[x].i << " " << vec1[x].j << endl;
    cin >> vec1[x].a;
  }
  
  bool d = false;
  for(int x =0; x<n; x++){
    fo(i, LG) fo(j, n+1) P[j][i] = -1;
    lvl[0] = -1;

    dfs(x+1, 0);

    for(i=1; i<LG; i++){
          Fo(j, 1, n+1)
              if (P[j][i-1] != -1)
                  P[j][i] = P[P[j][i-1]][i-1];
    }
    bool flag = true;
    for(auto f : vec1){
      if(lca(f.i, f.j) != f.a)
      {
        flag = false;
        // cout << "break" << x << " x " << y + 1 << " y " << endl;
        // cout << lca(y+1, n-y) <<  " " << vec[y] << "\n";
        break;
      }

    }
    if(flag){
      cout << "! " << x+1 << endl;
      d = true;
      break;
    }

  }
  

    
  return 0;
}