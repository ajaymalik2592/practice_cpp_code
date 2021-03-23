#include <bits/stdc++.h>

using namespace std;
const int N = 1000001;
int total[1000020], P[N], till[N];
int mod = 1e7 + 7;
int mul(int a, int b){
	return 1LL * a * b % mod;
}
int add(int a, int b){
	if(a + b >= mod)return a + b - mod;
	return a + b;
}
int sub(int a, int b){
	if(a  >= b)return a - b;
	return a - b + mod
	;
}
int power(int a, int b){
	int re = 1;
	while(b){
		if(b & 1)re = mul(re, a);
		a = mul(a, a);
		b >>= 1;
	}
	return re;
}
int inv(int a){
	return power(a, mod - 2);
}
int cal(int a, int co){
	// if(co == 1)return 1;
	return mul (sub(power(a, co + 1), 1), inv(a - 1));
}
int main() 
{
	cout << cal(2, 1) << '\n';
	cout << cal(2, 2) << '\n';
	total[1] = 1;
	P[1] = 1;
	for(int x = 2; x< N; x++){
		if(P[x] == 0){
			for(int y = x; y< N; y += x)if(P[y] == 0)P[y] = x;
		}
	}
	int ans = 1;
	for(int x = 2; x< N; x++){
		int x1  = x;
		while(x1 > 1){
			int fa = P[x1];
			int co = 0;
			while(x1 % fa == 0){
				co ++;
				x1 /= fa;
			}
			ans = mul(ans, inv(cal(fa, till[fa])) );
			till[fa] += co;
			ans = mul(ans,cal(fa, till[fa]));
		}
		total[x] = ans;
	}
	for(int x = 1; x<= 10; x++){
		cout << x << " " << till[x] << '\n';
	}
	while(1){
		int n;
		cin >> n;
		if(n == 0)break;
		cout << total[n] << "\n";
	}
}                   