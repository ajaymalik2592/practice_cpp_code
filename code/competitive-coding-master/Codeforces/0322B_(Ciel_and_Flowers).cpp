#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector< int >
#define vl vector< ll >
#define pii pair< int, int >
#define pll pair< ll , ll >
#define pdd pair< double, double >
#define vii vector< pii >
#define vll vector< pll >
#define vd vector< double >
#define vb vector< bool >
#define el "\n"
#define fio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ull unsigned long long int
#define ld long double
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define RFOR(i, b, a) for(int i=b; i>=a; i--)
#define all(vec) (vec).begin(),(vec).end()
#define rall(vec) (vec).rbegin(),(vec).rend()

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
        cerr << *it << " =: " << a << "\n";
   // cerr << "\n";
        err(++it, args...);
}

template <typename T1, typename T2>
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p)
{
   return os << "(" << p.first << ": " << p.second << ")";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v)
{
   bool first = true;
   os << "[";
   for(unsigned int i = 0; i < v.size(); i++)
   {
       if(!first)
           os << ", ";
       os << v[i];
       first = false;
   }
   return os << "]";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::set<T>& v)
{
   bool first = true;
   os << "{";
   for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
   {
       if(!first)
           os << ", ";
       os << *ii;
       first = false;
   }
   return os << "}";
}

template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v)
{
   bool first = true;
   os << "{";
   for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
   {
       if(!first)
           os << ", ";
       os << *ii ;
       first = false;
   }
   return os << "}";
}

template<typename T>
inline std::ostream &operator << (std::ostream & os,const std::unordered_set<T>& v) {
   return os << std::set<T>(v.begin(), v.end());
}

template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v) {
   return os << std::map<T1, T2>(v.begin(), v.end());
}

const ll MOD = 1e9+7;
const ll INF = 1e18;
const double EPS = 1e-6;

/***********************************************************************/

int main()
{
   fio;
   ll n, x, y, m;
   vector<ll> a(3);
   cin >> a[0] >> a[1] >> a[2];
   sort(all(a));
   ll ans = 0;
   for (int i = 0; i < 3; ++i) {
       ll b = a[0] - i;
        if (b < 0) continue;
       for (ll e: a) b += (e - (a[0] - i)) / 3;
       ans = max(ans, b);
       error(b)
   }
   cout << ans;

   return 0;
}