#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
#define int long long
i64 INF = 1e18, NIN = -1 * INF;
struct Node {
  i64 minv, lz;
  Node(): minv(), lz() {}
  friend Node operator + (const Node &lhs, const Node &rhs) {
    Node node;
    node.minv = min(lhs.minv, rhs.minv);
    return node;
  }
  //~ friend ostream &operator << (ostream &os, const Node &p) {
    //~ return os << "<" << p.minv << ", " << p.lz << ">";
  //~ }
};
struct SegTree {
  #define li (i + i)
  #define ri (i + i + 1)
  vector<int> ss, ee;
  vector<Node> t;
  SegTree(int n): ss(n << 2), ee(n << 2), t(n << 2) {
    build(1, 1, n);
    for(int x = 0; x< (n<<2); x++)t[x].minv = 0;
  }
  void build(int i, int l, int r) {
    ss[i] = l, ee[i] = r;
    if (l == r) { return; }
    int m = (l + r) >> 1;
    build(li, l, m); build(ri, m + 1, r);
  }
  inline void push(int i) {
    i64 &lz = t[i].lz;
    if (lz == 0) { return; }
    i64 len = ee[i] - ss[i] + 1;
    t[i].minv += lz;
    if (len > 1) {
      t[li].lz += lz;
      t[ri].lz += lz;
    }
    lz = 0;
  }
  inline void update(int i, int us, int ue, i64 a) {
    if (us <= ss[i] && ee[i] <= ue) {
      t[i].lz += a;
      push(i); return;
    }
    push(i);
    if (ue < ss[i] || ee[i] < us) { return; }
    update(li, us, ue, a); update(ri, us, ue, a);
    t[i] = t[li] + t[ri];
  }
  inline Node ask(int i, int qs, int qe) {
    push(i);
    if (qs == ss[i] && qe == ee[i]) { return t[i]; }
    if (qe <= ee[li]) { return ask(li, qs, qe); }
    if (qs >= ss[ri]) { return ask(ri, qs, qe); }
    return ask(li, qs, ee[li]) +
      ask(ri, ss[ri], qe);
  }
  void update(int L, int R, i64 val) {
    return update(1, L, R, val);
  }
  i64 ask(int L, int R) {
    if(R == 0)return 0LL;
    return min( 0LL,  ask(1, L, R).minv);
  }
  #undef li
  #undef ri
  //~ void debug(int i = 1) {
    //~ auto nn = make_pair(make_pair(ss[i], ee[i]), t[i]);
    //~ error(nn);
    //~ if (ss[i] == ee[i]) { return; }
    //~ debug(li); debug(ri);
  //~ }
};


struct Node1 {
  i64 minv, lz;
  Node1(): minv(), lz() {}
  friend Node1 operator + (const Node1 &lhs, const Node1 &rhs) {
    Node1 node;
    node.minv = max(lhs.minv, rhs.minv);
    return node;
  }
  //~ friend ostream &operator << (ostream &os, const Node &p) {
    //~ return os << "<" << p.minv << ", " << p.lz << ">";
  //~ }
};
struct SegTree1 {
  #define li (i + i)
  #define ri (i + i + 1)
  vector<int> ss, ee;
  vector<Node1> t;
  SegTree1(int n): ss(n << 2), ee(n << 2), t(n << 2) {
    build(1, 1, n);
    for(int x = 0; x< (n<<2); x++)t[x].minv = 0;
  }
  void build(int i, int l, int r) {
    ss[i] = l, ee[i] = r;
    if (l == r) { return; }
    int m = (l + r) >> 1;
    build(li, l, m); build(ri, m + 1, r);
  }
  inline void push(int i) {
    i64 &lz = t[i].lz;
    if (lz == 0) { return; }
    i64 len = ee[i] - ss[i] + 1;
    t[i].minv += lz;
    if (len > 1) {
      t[li].lz += lz;
      t[ri].lz += lz;
    }
    lz = 0;
  }
  inline void update(int i, int us, int ue, i64 a) {
    if (us <= ss[i] && ee[i] <= ue) {
      t[i].lz += a;
      push(i); return;
    }
    push(i);
    if (ue < ss[i] || ee[i] < us) { return; }
    update(li, us, ue, a); update(ri, us, ue, a);
    t[i] = t[li] + t[ri];
  }
  inline Node1 ask(int i, int qs, int qe) {
    push(i);
    if (qs == ss[i] && qe == ee[i]) { return t[i]; }
    if (qe <= ee[li]) { return ask(li, qs, qe); }
    if (qs >= ss[ri]) { return ask(ri, qs, qe); }
    return ask(li, qs, ee[li]) +
      ask(ri, ss[ri], qe);
  }
  void update(int L, int R, i64 val) {
    return update(1, L, R, val);
  }
  i64 ask(int L, int R) {
    if(R == 0)return 0;
    return ask(1, L, R).minv;
  }
  #undef li
  #undef ri
  //~ void debug(int i = 1) {
    //~ auto nn = make_pair(make_pair(ss[i], ee[i]), t[i]);
    //~ error(nn);
    //~ if (ss[i] == ee[i]) { return; }
    //~ debug(li); debug(ri);
  //~ }
};
int32_t main(){
  int t;
  cin >> t;
  for(int x = 1; x<= t; x++){
    int n, q;
    cin >> n >> q;
    SegTree mi(n);
    SegTree1 ma(n);
    // for(int y = 1; y<= n; y++){
    //   cout << ma.ask(x, x) << " ma " << mi.ask(x, x) << " mi\n"; 
    // }
    // mi.update(0,0,0);
    // ma.update(0,0,0);
    for(int y = 1; y<= n; y++){
      i64 u;
      cin >> u;
      mi.update(y, n, u);
      ma.update(y, n, u);
    }
    for(int y = 0; y<q; y++){
      char c;
      cin >> c;
      if(c == 'Q'){
        int l, r;
        cin >> l >> r;
        cout << ma.ask(r, n) - mi.ask(1,l-1) << "\n";
      }
      else{
        i64 i, val;
        cin >> i >> val;
        i64 o = ma.ask(i, i) - ma.ask(i-1, i-1);
        // cin >> i >> val;
        val -= o;
        ma.update(i, n, val);
        mi.update(i, n, val);
      }
    }
  }
}