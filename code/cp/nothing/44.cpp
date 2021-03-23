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
int const N = 100000 + 5;
int fact[N], inverse[N];
void FAC(){
 	fact[0] = 1;
	for(int x = 1; x< N; x++){
		fact[x] = mul(fact[x-1], x);
	}
	inverse[N-1] = power(fact[N-1], mod -2);
	for(int x = N-2; x>= 0; x--){
		inverse[x] = mul(x + 1, inverse[x+1]);
	}

 }

int ncr(int a, int b){
	if(a < b)return 0;
	return mul(fact[a], mul(inverse[a-b], inverse[b]));
}


/******************************************************/
void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> vec(n, vector<int> (m));
	for(auto &a : vec)for(auto &b : a)cin >> b;
	vector<pair<int, int>> good(m);
	for(int x = 0; x<m; x++)good[x] = {vec[0][x], 1};
	for(int x =1; x<n; x++){
		for(int y = 0; y<m; y++){
			if(good[y].first > vec[x][y]){
				good[y].first = vec[x][y];
				good[y].second = x+1;
			}
		}
	}
	sort(ALL(good));
	if(m == 1){
		cout << good[m-1].second << " " << good[m-1].second;
	}
	else{
		cout << good[m-1].second << " " << good[m-2].second;
	}
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
