#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	int k;
	cin >> k;
	vector<int> vec(10, 0);
	for(auto f : s)vec[f - '0']++;
	int ans = k;
	int p = 0;
	for(int x = 0; x<10; x++){
		ans -= vec[x];
		p = x;
		if(ans <= 0)break;
	}
	cout << p;
}