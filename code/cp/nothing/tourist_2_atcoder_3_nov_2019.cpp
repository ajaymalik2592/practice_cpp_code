#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int test = 1; test <= t; test++){

    cout << "Case #" << test << ": ";
    FenwickTree f = FenwickTree (5 + 1e5);
    int n;
    cin >> n;
    int ans = 0;
    vector<int> ans1(n);
    for(int x =0; x<n; x++){
      int i;
      cin >> i;
      f.add(i-1, 1);
      int p = f.sum(ans, 1e5);
      if(ans + 1 == p)ans++;
      ans1[x] = ans;
    }
    cout << ans1[0];
    for(int x = 1; x<n; x++)cout <<" " <<  ans1[x];
    cout << "\n";
  }
}
