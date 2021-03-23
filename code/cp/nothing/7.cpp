#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	vector<int> vec(10, 0);
	for(auto f : s)vec[f - '0']++;
	string p = "";
	for(int x = 0; x<10; x++){
		for(int y = 0; y<vec[x]; y++)p += '0' + x;
	}
	cout << p;
}