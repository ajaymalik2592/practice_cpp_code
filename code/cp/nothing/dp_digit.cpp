#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

int mul(int a, int b){
  return 1LL * a * b  % mod;
}
int power(long long a, long long b){
  a %= mod;
  int re = 1;
  while(b){
    if(b&1) re = mul(re ,a);
  a = mul(a, a);
  b>>= 1;
  }
return re;
}
vector<vector<long long> >  mul1(vector<vector<long long> >  a, vector<vector<long long> >  b){
    vector<vector<long long> >re = {{0,0,0}, {0,0,0}, {0,0,0}};

  for(int x =0; x<3; x++){
    for(int y =0; y<3; y++){
      for(int k=0; k<3; k++){
        re[x][y] += mul(a[x][k], b[k][y]);
      }
      re[x][y] %= mod;
    }
  }
  return re;
}

void solve(){
  long long a;
  cin >> a;
  vector<int> v = {2, 5 ,13};
  if(a < 4){
    cout << v[a-1] << "\n";
    return ;
  }
  a -= 3;
  vector<vector<long long> > a1 = {{2,1,1}, {1,0,0}, {0,1,0}}, re = {{1,0,0}, {0,1,0}, {0,0,1}};
  while(a){
    if(a&1) re = mul1(re ,a1);
    a1 = mul1(a1, a1);
    a>>=1;
  }
  // for(int x =0; x<4; x++){
  //  for(int y =0; y<4; y++){
  //    cout << re[x][y] << " ";
  //  }
  //  cout << endl;
  // }
  cout <<  (re[0][0]* 13 + re[0][1]*5 + re[0][2]*2 ) % mod << "\n";
}
 
int main(){
  int t;
  cin >> t;
  while(t--){
    solve();
  }
}