#include<bits/stdc++.h>
using namespace std;
int main(){
	char c;
	while(cin >> c)
	{
		int i = c;
		if(i == 39) i = 34;
		cout << char(i);
	}
}