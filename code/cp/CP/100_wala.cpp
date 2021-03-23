#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int add(int a, int b){
	if(a + b >= mod)return a + b - mod;
	return a + b;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int test;
	cin >> test;
	while(test--){
		string s, s1, s2;
		cin >> s;
		s1 = s;
		s2 = s1;
		int ans = 0;
		for(auto f : s){
			ans += f - 'a';
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		reverse(s2.begin(), s2.end());
		if( s.length() == 1 || ans == 0){
			cout << -1 << "\n";
		}
		else{
			string d = "";
			int u = ans;
			int n = s.length();
			for(int x =0; x<s.length(); x++){
				int left = (n-x-1) * 25;
				int p = u - left;
				if(p >= 0){
					d += 'a' + p;
					u -= p;
				}
				else{
					d += 'a';
				}
			}

			do{
				if(d != s){
					cout << ans << " " <<  d << "\n";
					break;
				}

			}while(next_permutation(d.begin(), d.end()));
		}
		
	}
}