/* Important Observation: We atmost add n times
 * Let the current length be L. If p is atmost half the length of L,
 * we can add p values directly to the points.
 * But when p is greater than half the current size L, we "flip"
 * (reverse) the segment, and add L - p values from the right.
 * For the queries, to find the sum in log n, we use Fenwick tree.
 * Maintaining the left and right pointers can be tricky, but thats
 * just implementation detail. 
*/
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define SZ(v) (int((v).size()))
#define ALL(vec) (vec).begin(),(vec).end()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
using namespace std;
template<typename T, typename V = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, V, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; // find_by_order(), order_of_key()

using ll = long long int;
using i64 = long long int;
template <typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template <typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}

void err(__attribute__((unused)) istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << a << endl;
  err(++it, args...);
}
template <typename T1, typename T2>
inline ostream& operator << (ostream& os, const pair<T1, T2>& buf) {
  return os << "(" << buf.first << ": " << buf.second << ")";
}
template<typename T>
inline ostream &operator << (ostream & os,const vector<T>& v) {
  bool first = true;
  os << "[";
  for (const auto &e: v) {
    if(!first) os << ", ";
    os << e;
    first = false;
  }
  return os << "]";
}
template<typename T>
inline ostream &operator << (ostream & os,const set<T>& v) {
  bool first = true;
  os << "{";
  for (auto ii = v.begin(); ii != v.end(); ++ii) {
    if(!first) os << ", ";
    os << *ii;
    first = false;
  }
  return os << "}";
}
template<typename T>
inline ostream &operator << (ostream & os,const unordered_set<T>& v) {
  bool first = true;
  os << "{";
  for (const auto &x : v) {
    if(!first) os << ", ";
    os << x;
    first = false;
  }
  return os << "}";
}
template<typename T1, typename T2>
inline ostream &operator << (ostream & os,const map<T1, T2>& v) {
  bool first = true;
  os << "{";
  for (const auto &e : v) {
    if(!first) os << ", ";
    os << e;
    first = false;
  }
  return os << "}";
}
template<typename T>
ostream &operator << (ostream & os,const vector<vector<T>>& v) {
  for (auto &u: v) os << '\n' << u;
  return os;
}
template<typename T>
void finish(T ans) {cout << ans << '\n'; exit(0);}
int const MOD = 1e9 + 7;
long long const INF = 1e18;
#define PI 3.14159265358979323846
/***********************************************************************/
template <class T>
struct Fenwick {
    const int n;
    vector<T> bit;
    Fenwick(int _n): n(_n), bit(n + 1, 0) {};
    Fenwick(int _n, int inival): n(_n), bit(n + 1, 0) {
      for (int i = 1; i <= n; ++i)
        add(i, inival);
    }
    T ask(int R) {
        T ans = 0;
        for(int x = R; x > 0; x -= x & -x)
            ans += bit[x];
        return ans;
    }
    T ask(int L, int R) {
        return ask(R) - ask(L - 1);
    }
    T at(int pos) {
      return ask(pos, pos);
    }
    void add(int pos, T v) {
        if(pos <= 0) return;
        for(; pos <= n; pos += pos & -pos)
            bit[pos] += v;
    }
    vector<T> values(int upto = -1) {
        if (upto == -1) return values(n);
        vector<T> fenwick_values;
        for (int i = 1; i <= upto; ++i)
            fenwick_values.push_back(ask(i, i));
        return fenwick_values;
    }
};
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  Fenwick<int> fen(n, 1);
  int fp = 1, tp = n, flip = 0;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p; cin >> p;
      if (p > (tp - fp + 1) / 2) {
        flip ^= 1;
        p = tp - fp + 1 - p;
      }
      if (flip) {
        for (int i = tp - p, j = i + 1; j <= tp; ++j, --i) {
          fen.add(i, fen.at(j));
        }
        tp -= p;
      } else {
        for (int j = fp + p, i = j - 1; i >= fp; --i, ++j) {
          fen.add(j, fen.at(i));
        }
        fp += p;
      }
    } else {
      int x, y;
      cin >> x >> y;
      if (flip) {
        swap(x, y);
        x = tp - fp + 1 - x;
        y = tp - fp + 1 - y;
      }
      cout << fen.ask(fp + x, fp + y - 1) << '\n';
    }
  }
    
  return 0;
}
