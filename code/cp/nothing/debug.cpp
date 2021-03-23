#include <bits/stdc++.h>
using namespace std;
 
#define ub        upper_bound            // first element >  val(itr)
#define lb        lower_bound            // first element >= val(itr)
 
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define mem(a,b) memset( a, b, sizeof(a) )
#define x first
#define y second
 
#define bitcount(a) __builtin_popcount(a)   // count set bits
#define lzcount(x) __builtin_clz(x)        // count leading zeros in binary representation of number
#define tzcount(x) __builtin_ctz(x)        // count trailing zeros in binary representation of number
 
#define FAST ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
 
typedef long long ll;
typedef long double lld;
const ll MOD = 1e9+7;
const lld PI = acos(-1.0);
 
template<typename T> T gcd(T a,T b){ if(b>a) return gcd(b,a);return b==0?a:gcd(b,a%b); }
template<typename T> T lcm(T a, T b) { return a * b / gcd(a, b); }
template<typename T> T fast_power(T x,T y,ll m=MOD){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1LL;x=(x*x)%m;}return ans%m;}
template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
 
inline ll mod(ll x,ll n) {if (x < n) return x; if (x >= n) return x - n;}
string IntToString(ll a){ ostringstream temp; temp << a; return temp.str();}
ll findMMI_fermat(ll n,ll M) {ll ans= fast_power(n,M-2,M);return ans;}//i.e In (a/b)%M..it calculates MMI of b wrt M,only if M is prime
ll add(ll a,ll b,ll M)  { return mod(( mod(a,M ) + mod(b,M )),M);     }
ll sub(ll a, ll b,ll M) { return mod((mod(a,M ) + M - mod(b,M )),M);   }
ll mult(ll a,ll b,ll M) { return  mod(( mod(a,M)*mod(b,M) ),M) ; }
bool isprime(ll a){ if(a==2) {return 1;}if(!(a&1) ) {return 0;}for(ll i=3;i*i<=a;i+=2){if(a%i==0) {return 0;} } return 1;} 
 
ll gcdExtended(ll a, ll b, ll *x, ll *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd1= gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd1;
}
 
ll modInv(ll a, ll m){
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x%m + m) % m;
    return res;
}
 
               /* -------------------------------Main Code------------------------------- */
 
 
int main(){
    FAST
    int t;cin>>t;
    while(t--){
        while(t--){
            string s,r;cin>>s>>r;
            string temp;
            int cnt1[26]={0},cnt2[26]={0};
            for(int i=0;i<sz(s);i++){
                cnt1[s[i]-'a']++;
            }
            for(int i=0;i<sz(r);i++){
                cnt2[r[i]-'a']++;
            }
            int poss = 1;
            for(int i=0;i<26;i++){
                if(cnt2[i]<cnt1[i]){
                    poss=0;
                }
                cnt2[i]-=cnt1[i];
            }
            //cout<<"A"<<endl;
            temp.reserve(sz(r));
            if(poss){
                int stop = s[0]-'a';
                //int x = 0;
                for(int i=0;i!=stop;i++){
                    temp.append(cnt2[i], (i+'a'));
                    //x+=cnt2[i];
                }
                temp += s;
                //x+=sz(s);
                for(int i=stop;i<26;i++){
                    temp.append(cnt2[i], (i+'a'));
                    //x+=cnt2[i];
                }
                cout<<temp<<endl;
            }
            else{
                cout<<"Impossible"<<endl;
            }
        }
    }
    return 0;
}
