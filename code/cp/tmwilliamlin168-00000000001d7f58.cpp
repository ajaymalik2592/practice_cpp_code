#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, c[2000001][26], m, cnt[2000001];
int ans;

void dfs(int u=0, int d=0) {
	for(int v=0; v<26; ++v)
		if(c[u][v])
			dfs(c[u][v], d+1), cnt[u]+=cnt[c[u][v]];
	ans += (cnt[u] / k ) * d;
	cnt[u] %= k;
}
bool fun(string a){
	string s = a;
	for(int x =0; x<a.length(); x++){
		if(s[x] != s[a.length() - 1- x])return 0;
	}
	return 1;
}
void solve() {
	long double n;
	cin >> n;
	n /= 3;
	printf("%Lf" ,n * n * n );
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t= 1, i=1;
	// cin >> t;
	while(t--) {
		// cout << "Case #" << i << ": ";
		solve();
		++i;
	}
}