#include <bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;
#define pb push_back
int mul(int a, int b){
	return 1LL * a * b % mod;
}
int add(int a, int b){
	if(a + b >= mod)return a + b - mod;
	return a + b;
}
vector<int> fun(string s){
	string till = "";
	vector<int> v;
	for(int x = 2; x<int(s.length()); x++){
		if(s[x] == ':'){
			v.pb(stoi(till));
			till = "0";
		}
		else
		{
			till += s[x];
		}
	}
	v.pb(stoi(till));
	assert(v.size() == 6);
	return v;
}

int main() 
{
	ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int day = 9 * 3600 + 30 * 60;
	int eve = 12 * 3600 + 30 * 60 ;
	int before = day - 3600;
	while(1){
		int n;
		cin >> n;
		if(n == 0)break;
		int co = 0;
		for(int x = 0; x<n; x++){
			string s;
			cin >> s;
			vector<int> v = fun(s);
			int s1 = v[0] * 3600 + v[1] * 60 + v[2];
			int s2  = v[3] * 3600 + v[4] * 60 + v[5];
			if(s[0] == 'D'){
				
				if(s1 > day)continue;
				s1 = max(s1, before);
				s2 -= s1;
				if(s2 >= 3600 * 8)co++;
			}
			else{
				if(s1 > eve)continue;
				s1 = max(s1, before);
				s2 -= s1;
				if(s2 >= 3600 * 9)co++;
			}
		}
		n -= co;
		if(n == 0){
			cout << "ALL OK";
		}
		else if(n < 4){
			cout << n << " Point Deducted";
		}
		else{
			cout << "Issue Show Cause Letter";
		}
		cout << "\n";
	}
	return 0;
}                   