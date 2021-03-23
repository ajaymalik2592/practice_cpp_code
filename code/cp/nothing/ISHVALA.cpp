#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
  	long long n, k;
  	cin >> n >> k;
  	string s;
  	cin >> s;
  	int i =0;
  	map<char , vector<int>> ma;
  	for(auto a : s){
  		ma[a].push_back(i++);
  	}
  	i =0;int p =0, si =0;
  	while(i < ma['0'].size()){
  		p = lower_bound(ma['1'].begin(), ma['1'].end() , ma['0'][i]) - ma['1'].begin();
  		if(p <= k)k -= p, i++;
  		else {
  			for(int x =0; x<i; x++)cout << '0', si++;
  			for(int x = 0; x<p-k; x++)cout << 1, si++;
  			cout << "0";si++;
  			for(int x = p-k; x<p; x++)cout << '1', si++;
  				break;
  		}
  	}
  	if(si == 0){
  		sort(s.begin(), s.end());
  		cout << s << "\n";
  	}
  	else{
  		for(int x = si; x<s.length(); x++)
  			cout << s[x];
  		cout << "\n";
  	}



  }

  return 0;
}
