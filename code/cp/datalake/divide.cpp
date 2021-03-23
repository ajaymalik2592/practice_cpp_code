#include<bits/stdc++.h>
using namespace std;
int main(){
	char c;
	cout << "read seprator\n";
	cin >> c;
	string s;
	while(cin >> s){
		int p = s.find(c);
		cout << s.substr(p+1) << "\n";
	}
}