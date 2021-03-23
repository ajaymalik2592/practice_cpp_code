#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int mod = 1e9  +7;
int mul(int a, int b){
	return 1LL * a * b  % mod;
}
int add(int a, int b){
	if(a + b >= mod)return a + b - mod;
	return a + b;
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
int main(){

	// cout << (3 & 1) << endl;
	int fact[100001], inverse[100001];
	fact[0] = 1;
	for(int x = 1; x<= 1e5; x++){
		fact[x] = mul(fact[x-1], x);
	}
	inverse[100000] = power(fact[100000], mod -2);
	for(int x = 1e5-1; x>= 0; x--){
		inverse[x] = mul(x + 1, inverse[x+1]);
	}

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 1;
		vector<int> vec(2*n);
		ll sum = 0, s;
		map<int, int> ma;
		for(auto &a : vec)cin >> a, sum += a, ma[a]++;
		bool flag = true;
		s = sum;
		sum /= n + 1;
		int s_count, half_count = 0;
		ma[sum] += 0;
		ma[0] += 0;
		for(auto  A : ma){
			if(A.first == 0 || A.first == sum){
				if((A.second  + ma[sum- A.first]) % 2)flag = false;
				continue;
			}
			if(A.second != ma[sum - A.first] )flag = false;
		}
		for(auto a : vec){
			if(a == sum)s_count++;
			if(a == sum/2)half_count++;
		}
		if(!flag || s % (n+1) ){
			cout << 0 << "\n";
		}
		else if(ma[sum] < 2){
			cout << 0 << "\n";
		}
		else{
			int expo = n - 1;
			ma[sum] -= 2;
			// cout << " sum " << sum << "  --  ";
			if(sum % 2 == 0){
				// cout << "  run  ";
				expo -= half_count/2;
				if(sum == 0)expo++;
			}
			int a1 = sum / 2;
			vector<int> res;
			for(auto a : ma){
				if(a.first == min(a.first, int(sum - a.first))){
					if(a.first != sum - a.first)
						res.push_back(a.second);
					else 
						res.push_back((a.second)>>1);
				}
			}
			int ans1 = fact[n-1];
			for(auto a : res){
				// cout << a << " ";
				ans1 = mul(ans1, inverse[a]);
			}
			// cout << ans1 << " " << expo << " -- ";
			cout << mul(ans1, power(2, expo)) << "\n";

		}
	}
}