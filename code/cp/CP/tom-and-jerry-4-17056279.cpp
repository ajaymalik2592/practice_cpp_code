#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define ALL(a) (a).begin() , a.end()
// bool fuck = false;
int mod = 1e9 + 7;
int add(int a, int b){
  if(a + b >= mod)return a+ b - mod;
  return a + b;
}
int mul(int a, int b){
  return 1LL * a * b  % mod;
}
int power(int a, int b){
  int re = 1;
  while(b){
    if(b&1)re= mul(re, a);
    a = mul(a, a);
    b>>=1;
  }
  return re;
}
int const N = 100 *1001;
typedef long long i64;
/********************i**********************************/
int n, t[4*N];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = __gcd(t[v*2] , t[v*2+1]);
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return __gcd(sum(v*2, tl, tm, l, min(r, tm))
           ,sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = __gcd(t[v*2] , t[v*2+1]);
    }
}
vector<vector<int>> mull(vector<vector<int> >a , vector<vector<int>> b){
  vector<vector<int>> re = {{0, 0}, {0 , 0}};
  for(int x =0; x<2; x++){
    for(int y = 0; y<2; y++){
      for(int z =0; z<2; z++){
        re[x][y] = add(re[x][y], mul(a[x][z], b[z][y]));
      }
    }
  }
  return re;
}
 
int power(int b){
  if(b == 1)return 0;
  b--;
  vector<vector<int>> re = {{1, 0}, {0 , 1}}, a = {{1,1},{1,0}};
  while(b){
    if(b&1)re= mull(re, a);
    a = mull(a, a);
    b>>=1;
  }
  return re[0][0];
}
void solve(){
  int n, q;
  cin >> n >> q;
  int a[n];
  for(int x =1-1; x<n; x++)cin >> a[x], a[x] = power(a[x]);
  build(a,1,0,n-1);
  for(int x =0; x<q; x++){
    int i, j;
    cin >> i , j;
    // cout << x << endl;
    cout << sum(1,0,n-1,i-1,j-1) << "\n";
  }
}

/******************************************************/
int main()
{
  // Node raja;
  // for(int x = 0; x<= 10; x++)raja.cir[x] = 0;
  // raja.cir[0] = 1;
  // raja.lz = 5;
  // // raja.call();
  // cout << raja.cir[5] << endl;
  // for(int x = 0; x<=10; x++){
  //   cout << " x " << x <<  " " << raja.cir[x] << endl;
  // }
  ios_base::sync_with_stdio(false);cin.tie(nullptr);
  int tt;
  tt = 1;
  // cin >> t;
  while(tt--){
    solve();
  }
}