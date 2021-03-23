#include<bits/stdc++.h>
using namespace std;
vector<string> split(string s){
	string a = "";
	vector<string> vec;
	for(char b : s){
		if(b == ' '){
			vec.push_back(a);
			a.clear();
		}
		else a += b;
	}
	vec.push_back(a);
	for(auto v : vec)cout << v << endl;
	return vec;
}
int main(){
	string s;
	getline(cin, s);
	vector<string> vec = split(s);
	string ans = "";
	for(int x =0; x<vec.size() / 2; x++){
		ans += vec[vec.size() -1 - x];
		ans += " " + vec[x];
		if(!(x == vec.size()/2 - 1 &&  vec.size() % 2 == 0))
		ans +=   " ";
	}
	if(vec.size() % 2 )ans += vec[vec.size()/2];
	cout << ans ;
}