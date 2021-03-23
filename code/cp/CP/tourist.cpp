/**
 *    author:  tourist
 *    created: 03.11.2019 18:32:17       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  int min_b = *min_element(b.begin(), b.end());
  int max_a = *max_element(a.begin(), a.end());
  int ans = 0;
  vector<pair<int, int>> p(n);
  vector<pair<pair<int, int>, int >> p1(n);
  for (int i = 0; i < n; i++) {
    p[i] = make_pair(min_b - a[i] + 1, b[i] - max_a + 1);
    p1[i] = make_pair(make_pair(min_b - a[i] + 1, b[i] - max_a + 1), i );
  }
  sort(p.begin(), p.end());
  sort(p1.begin(), p1.end());
  debug_out(p1);

  int m2 = (int) 1.01e9;
  for (int i = 0; i < n - 1; i++) {
    m2 = min(m2, p[i].second);
    ans = max(ans, p[i + 1].first + m2);
  }
  for (int i = 0; i < n; i++) {
    int cur = b[i] - a[i] + 1;
    cur += max(0, min_b - max_a + 1);
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}
