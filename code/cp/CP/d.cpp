#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define ALL(a) (a).begin() , a.end()

int mod = 1e9 + 7;

int add(int a, int b){
	if(a + b >= mod)return a+ b - mod;
	return a + b;
}
int mul(int a, int b){
	return 1LL * a * b  % mod;
}
int power(int a, int b){
	if(b < 0)return 0;
	int re = 1;
	while(b){
		if(b&1){
			re = mul(re, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return re;
}
// int const N = 100000 + 5;
// int fact[N], inverse[N];
// void FAC(){
//  	fact[0] = 1;
// 	for(int x = 1; x< N; x++){
// 		fact[x] = mul(fact[x-1], x);
// 	}
// 	inverse[N-1] = power(fact[N-1], mod -2);
// 	for(int x = N-2; x>= 0; x--){
// 		inverse[x] = mul(x + 1, inverse[x+1]);
// 	}

//  }

// int ncr(int a, int b){
// 	if(a < b)return 0;
// 	return mul(fact[a], mul(inverse[a-b], inverse[b]));
// }


/******************************************************/
int fun(ll a){
	vector<int> v;
	int n = 0;
	while(a){
		v.pb(a%10);
		a /= 10;
		if(n >= 2){
		if(v[n]> 0 && v[n] +2 == v[n-1] +1 && v[n-1]+1 == v[n-3+1])return 1;
		}
		n ++;
	}
	return 0;
}

ll dp[20][10][5];
void go(){
	for(int x = 1; x<10; x++){
		dp[1][x][1] = 1;
	}
	dp[1][0][1] = 0;
	for(int len = 2; len <= 19; len++){
		for(int val = 0; val< 10; val++){
			for(int x = 0; x<5; x++)dp[len][val][x] = 0;
			for(int inside = 0; inside <= 9; inside++){
				if(val > 0 && val + 1 == inside){
					for(int y = 1; y<= 2; y++){
						dp[len][val][y+1] += dp[len-1][inside][y];
					}
					dp[len][val][1] += 1;
					dp[len][val][2] += dp[len-1][inside][2];
					dp[len][val][3] += dp[len-1][inside][3];
				}
				else{
					// for(int y = 3; y<= 3; y++)
					dp[len][val][3] += dp[len-1][inside][3];
					// dp[len][val][1] = dp[len][val][2] = 0;
					if(val != 0)
					dp[len][val][1] += 1;
				}
			}
		}
	}

}
bool good(string s){
	// cout << s <<  endl;
	for(int x = 0; x<s.length()-1; x++){
		if(s[x] == 0 || s[x] +1 != s[x+1])return 0;
	}
	return true;
}
ll cal(ll a){
	ll ans = 0;
	string s = to_string(a);
	int n = s.length();
	if(n == 19){
		return dp[n][0][3];
		// return ans;
	}
	// for(int x = 1; x<n; x++){
	// 	for(int y = 1; y<= 9; y++)ans += dp[x][y][3];
	// }
	// ans = dp[n][0][3];
	
	for(int x = n; x>= 1; x--){
		for(int y = 0; y< s[n-x] - '0'; y++){
			ans += dp[x][y][3];
		}
		
		if(x <=  n -2 && good(s.substr(n-x-2, 3))){
			ans += pow(10LL , x-1);
			return ans;
		}
	}
	return ans;
}
void solve(){
	long long l, r;cin >> l >> r;
	// int ans = 0;
	// if( r - l <= 1e7){
	// 	for(ll x = l ; x <= r; x++){
	// 	// if(fun(l))cout << l << " ";
	// 	ans += fun(x);
	// }
	// cout << ans << endl;
	// return;
	// }
	// else{
		go();
		// for(int x = 10000; x<= 2e4; x++){
		// 	if(fun(x)){
		// 		if(cal(x) - cal(x-1) == 0){
		// 			cout << x <<  " ";
		// 		}
		// 	}
		// }
		cout << cal(r) - cal(l-1) << "\n";
	// }
	
}


/******************************************************/
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	t = 1;
	// cin >> t;
	while(t--){
		solve();
	}

}
