#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int n;
    cin >> n; vector<int>vec(n);
    for(auto &a : vec)cin >> a;
    sort(vec.begin(), vec.end());
    for(int x = 0; x<n/2; x++)
    {
        ans += vec[n-1-x] - vec[x];
    }
    cout << ans;
 
} 