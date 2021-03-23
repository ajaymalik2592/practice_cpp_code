#include<bits/stdc++.h> 
using namespace std; 
const long long INF = 1e18;
int n;
vector<vector<pair<int, long long>>> adj(1e6 + 1);
void dijkstra() {
    vector<long long > d(n, 1e18);
    vector<int> p(n,-1); 
    
    d[0] = 0;
    set<pair<int, int>> q;
    q.insert({0, 0});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            auto len = edge.second;

            if (d[v] + len < d[to]) {
                if(q.count({d[to], to}) > 0)
                    q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], });
            }
        }
    }
    vector<int> path;

    for (int v = p[n-1]; v != -1; v = p[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    for(auto g : path)cout << g+1 << " ";

}

int main() 
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m, a, b;
    cin >> n >> m >> a >> b;
    for(int x =0; x<m; x++){
        int f, e ,t , c, h;
        cin >> f >> e >> t >> c >> h;
        f--, e--;
        adj[f].push_back({e, x});
    }
    dijkstra();
    return 0; 
} 
  
