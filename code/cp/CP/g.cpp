#include<bits/stdc++.h>
using namespace std;

#define mk make_pair
typedef long long ll;
bool cmp(pair<int,pair<int,int>> a,pair<int,pair<int,int>> b){
  if(a.first != b.first){
    return a.first < b.first;
  }
  return a.second > b.second;
}

int32_t main(){
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 int n, k; cin >> n >> k;
 
 using pii =pair<int,int> ;
 set<pair<int, pii>> se;
 vector<int> vec(n), ch(n, 0);
 int last = -1, change = 0;
 for(int x = 0;x<n; x++){
  int i;cin >> i;
  vec[x] = i;
  if(vec[x] >= 0){
    if(change == 0)
    {
      last = x;
    }
    change = 1;
  }
  else{
    ch[x] = 1;
    k--;
    if(change == 1 && last != -1){
      se.insert(mk(x - last 
        , mk(last, x-1)));
    }
    change = 0;
  }
 }
 pair<int, pii> pop = {-1, {-1, -1}};
if(change == 1){
  pop = mk(n- last, mk(last, n-1));
 }



 
 for(auto a : se){
  if(a.second.first == 0 )continue;
  if(a.first <= k){
    k -= a.first;
    for(int o =  a.second.first; o<= a.second.second; o++)ch[o] = 1;
  }
  else{
    break;
  }
 }
 if(pop.first != -1 && se.size() > 0)
 for(int x = pop.second.first; x<n && k > 0; x++, k--)
 {
  ch[x] = 1;
 }

 int answer = 0;
 change = 0;
 for(int x =0; x<n; x++){
  answer += change != ch[x];
  change = ch[x];
 }
// for(auto a : se)cout << a.first <<  " => " << a.second.first << " to " << a.second.second << endl; 
//  for(auto a:  ch)cout << a << " ";
//  cout << endl; 
 if(k < 0){
  cout << -1;
 }
 else{
  cout << answer;
 }
}