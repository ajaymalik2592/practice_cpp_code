#include<bits/stdc++.h>
using namespace std;
int mod = 10;
int power(int a, long long b){
	int re = 1;
	while(b){
		if(b&1)re = 1LL * re * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return re;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int test;
	cin >> test;
	while(test--){
		long long a, b, n;
		cin >> n >> a >> b;
    vector<int> vec;
    long long p = a+b;
    p %= mod;
    while(!count(vec.begin(), vec.end(), p)){
        vec.push_back(p);
        p *= 2;
        p %= mod;
    }
    for(int x : vec)cout << x << " ";
    cout << endl;
    int s = vec.size();
    int su = accumulate(vec.begin(), vec.end(), 0);
    p = 1LL * ((n-1)/ s) * su % 3;
   	n = (n-1)%s;
    for(int x =0; x<n; x++)p += vec[x];
    p = (p + a + b) % 3;
		if(p == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}