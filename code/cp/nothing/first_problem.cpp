#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
vector<int> parents(3e5 + 5), lvl(3e5 + 5);

void dfs(vector<int> vec[], int node, int par, int l)
{
    lvl[node] = l;
    parents[node] = par;
    for(auto a : vec[node])
    {
      if(a == par)continue;
      dfs(vec, a, node , l + 1);
    }
}

int lca(int u, int v, int p[][20]){
    int i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);

    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = p[u][i];
    }

    if (u == v) 
      return u;

    for(i=lg; i>=0; i--){
        if (p[u][i] != -1 and p[u][i] != p[v][i])
            u = p[u][i], v = p[v][i];
    }

    return p[u][0];
}


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    lvl.clear();
    parents.clear();

    int n, q;
    cin >> n >> q;
    vector<int> vec[n+1];
    for(int x =0; x<n-1; x++){
      int i, j;
      cin >> i >> j;
      vec[i].push_back(j);
      vec[j].push_back(i);
    }
    dfs(vec, 1, -1, 0);
    int p[n+5][20];
    int LG = 20;
    for(int x =1; x<=n; x++)
    {

      p[x][0] = parents[x];
      // cout <<x << " " <<  p[x][0] << " " ;
    }
    // cout << "ajay1" << endl;
    for(int i=1; i<LG; i++)
        {
          // cout << i <<  " ";

          for(int j = 1; j<=n; j++)
          {

            if (p[j][i-1] != -1)
                p[j][i] = p[p[j][i-1]][i-1];
            else
              p[j][i] = -1;

          }
        }
    // cout << "ajay2" << endl;
    // for(int x =1; x<= n; x++) cout << x << " " << val[x] << " ";
    for(int x =0; x<q; x++){
      long u, v, s1 , s2;
      cin >> u >> v >> s1 >> s2;
      long  co = lca(u, v, p);
      co = lvl[co];
      u = lvl[u], v = lvl[v];
      long   tot = u*(u+1)/2 + v*(v+1)/2;
      long  p1 = u - co, p2 = v - co;
      long  sr1 = s1 -  p1*(p1+1)/2,
      sr2 = s2 - p2*(p2+1)/2;
      if(sr1 < 0 || sr2 < 0 || (s1 + s2 < tot)){
        cout << -1 << "\n";
      }
      else{
        cout << s1 + s2 - tot << "\n";
       }
    }

  }
}