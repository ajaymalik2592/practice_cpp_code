#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
int mul(int a, int b){
	return 1LL * a * b % mod;
}
int power(int a, int b){
	a %= mod;
	int re =1;
	while(b){
		if(b&1) re = mul(re, a);
		a = mul(a, a);
		b >>= 1;
	}
	return re;
}
int add(int a, int b){
	if(a + b >= mod) return a+ b -mod;
	return a + b;
}
int fact(int a){
	int re =1;
	for(int x =1; x<= a; x++)
		re = mul(re , x);
	return re;
}
int main(){
	
	int t;
	cin >> t;
	while(t--){
		
 	}

}