#include<bits/stdc++.h>
using namespace std;
int si = 0;
vector<int> visited(2e5 + 1000 , 0);
void bfs(int a, vector<int> vec[]){
  visited[a] = 1;
  for(int b : vec[a]){
    if(visited[b] == 0){
      bfs(b, vec);
    }
  }
}
int main(){
  // int t;
  // cin >> t;
  // while(t--){
    int n;
    cin >> n;
    int ans=0;
    vector<int> vec[n + 100];
    set<char> se;
    for(int x =0; x<n; x++){
      string s;
      cin >> s;
      set<char> c;
      for(char a : s)c.insert(a);
      for(char a  : c){
        se.insert(a);
        vec[a - 'a'].push_back(x + 26);
        vec[x + 26].push_back(a - 'a');
      }
    }
      for(int x = 26; x<n+26; x++){
        if(visited[x] == 0){
          // queue<int> que;
          // que.push(x);
          // while(!que.empty()){
          //   int p = que.front();
          //   que.pop();
          //   visited[p ] = 1;
          //   for(int b : vec[p])
          //   {
          //     if(visited[b] == 0)que.push(b);
          //   }
          // }
          bfs(x, vec);
          ans++;
        }
      }
    // }
  
  cout << ans << "\n";

}