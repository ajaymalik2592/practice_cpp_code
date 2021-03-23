#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
int mod = 1e9 + 7;
int mul(int a, int b){
    return 1LL * a * b % mod;
}
int power(int a, int b){
    int re = 1;
    while(b){
        if(b&1)re = mul(re, a);
        a = mul(a, a);
        b >>= 1;
    }
    return re;
}
int main()
	{
	    int n = 1000 * 1000  + 1;
	    int fact[n] , inv[n];
	    fact[0] = 1, inv[0] = 0;
	    for(int x = 1; x<n; x++){
	        fact[x] = mul(fact[x-1], x);
	    }
	    inv[n-1] = power( fact[n-1], mod - 2);
	    for(int x = n -2; x>=0; x--){
	        inv[x] = mul(x+1, inv[x+1]);
	    }
	    cout << mul(fact[2] , inv[2] ) << " " << mul(fact[3], inv[3]) << endl;
 	    int t;
	    cin >> t;
	    while(t--){
	        string s;
	        cin >>s;
	        map<char, int> ma;
	        set<char> se = {'a', 'u', 'o', 'i', 'e'};
	        for(auto a : s)ma[a]++;
	        int odd = 1, even = 1;
	        int o =0, e = 0;
	        for(auto a : ma){
	           if(se.count(a.first)){
	               odd = mul(odd, inv[a.second]);
	               o += a.second;
	           }
	           else
	           {
	               e += a.second;
	               even = mul(even, inv[a.second]);
	           }
	        }
	        if(e + 1 < o){
	            cout << -1 << endl;
	        }
	        else{
	            cout << e <<   " "  << o << " ";
	            int ans = mul(fact[e+ 1],inv[e  + 1 - o]); 
	           	ans = mul(ans, odd);
	           	cout << ans << endl;

	            ans = mul(ans, even);
	            ans = mul(ans, fact[e]);
	            cout << ans << "\n";
	        }
	    }
	    
	   	return 0;
	}
