#include <bits/stdc++.h>
using namespace std;
#define SZ(v) int((v).size())
#define ALL(vec) begin(vec), end(vec)

typedef long long i64;
template<typename T> inline bool uax(T &x, T y) {return (y > x) ? x = y, true : false;}
template<typename T> inline bool uin(T &x, T y) {return (y < x) ? x = y, true : false;}
#ifdef Rahul
# define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
  stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#else
# define error(...) 42;
#endif
string to_string(char c) { return "'" + string(1, c) + "'";}
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
template<typename A> string to_string(A);
template<typename A, typename B> string to_string(pair<A, B> p){
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";}
template<typename A> string to_string(A v) {bool f = false; string r = "{"; 
  for (auto x: v) {if (f) r += ", "; r += to_string(x); f = true;} return r += "}";}
template<typename A> string to_string(vector<vector<A>> v) {string r; 
  for (auto x: v) r += "\n" + to_string(x); return r;}
int Nerr;
template<typename A> string to_string(A *p) {return to_string(vector<A>(p, p + Nerr));}
void err(istream_iterator<string>) { cerr << endl; }
template<typename T,typename... Args> void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " =: " << to_string(a) << "; "; err(++it, args...); }
template<typename T> void kek(T ans) {cout << ans << endl; exit(0);}
/***********************************************************************/
mt19937 rng(58);
inline int randint(int a, int b) {
  return uniform_int_distribution<int>(a, b)(rng);
}
inline auto gettime() {
  return std::chrono::high_resolution_clock::now();
}
inline int duration(auto d) {
  // time from d till now (in milliseconds)
  return (int) std::chrono::duration_cast<std::chrono::milliseconds>(gettime() - d).count();
}

int B, L, D;
vector<int> BookScore; // score for each book
vector<vector<int>> Library; // adj list of books available
vector<int> UpTime; // time for signup for library
vector<int> Limit; // no. of books per day

struct Result {
  int A;
  vector<int> order;
  vector<vector<int>> books;
};

Result bestAns;

void read_file() {
  cin >> B >> L >> D;
  BookScore.resize(B);
  Library.resize(L);
  UpTime.resize(L);
  Limit.resize(L);
  for (int i = 0; i < B; ++i) {
    cin >> BookScore[i];
  }
  for (int i = 0; i < L; ++i) {
    int numBooks; cin >> numBooks;
    cin >> UpTime[i] >> Limit[i];
    Library[i].resize(numBooks);
    for (int j = 0; j < numBooks; ++j) {
      cin >> Library[i][j];
    }
  }
}

void solve() {
  bestAns.order.resize(L);
  iota(ALL(bestAns.order), 0);
  sort(ALL(bestAns.order), [&] (int i, int j) {
    return UpTime[i] < UpTime[j];
  });
  for (int i : bestAns.order) {
    bestAns.books.push_back(Library[i]);
  }
}
void printAns() {
  cout << SZ(bestAns.order) << '\n';
  for (int i = 0; i < SZ(bestAns.order); ++i) {
    cout << bestAns.order[i] << ' ' << SZ(bestAns.books[i]) << '\n';
    for (int &j : bestAns.books[i]) {
      cout << j << ' ';
    }
    cout << '\n';
  }
}
int getScore(Result &res) {
  vector<int> marked(B);
  int tick = 0;
  for (int i : res.order) {
    tick += UpTime[i];
    if (tick >= D) break;
    int rem = D - tick;
    int ptr = 0;
    while (rem > 0) {
      int cnt = 0;
      while (ptr < SZ(res.books[i]) && cnt < Limit[i]) {
        int b = res.books[i][ptr];
        marked[b] = 1;
        ++ptr; ++cnt;
      }
      rem--;
      if (ptr == SZ(res.books[i])) break; 
    }
  }
  int score = 0;
  for (int i = 0; i < B; ++i) {
    score += marked[i] * BookScore[i];
  }
  return score;
}
int32_t main(int argc, char * argv[]) {
  cin.tie(nullptr) -> sync_with_stdio(false);
  
  if (argc > 1) rng.seed(atoi(argv[1]));
  
  read_file();
  
  solve();
  printAns();
  int myScore = getScore(bestAns);
  int totalBookScore = accumulate(ALL(BookScore), 0);
  cerr << myScore << " / " << totalBookScore << endl;
}



