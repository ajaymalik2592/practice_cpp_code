#include<bits/stdc++.h>
using namespace std;
pair<int,int> fun(int a, int b, int a1){
	if(a1 == 1)return {b^a, a};
	else if(a1 == 2) return {b , a^b};
	else  return {a, b};
	
}
pair<int,int> fun1(int a, int b, int a1, int b1){
	if(a1 == 0 && b1 == 0)return {a, b};
	else if(a1 == 1 && b1 == 0) return {a^b , b};
	else return {a^b, a};
}
int main()
{

	int t;
	cin >> t;
	while(t--)
	{	
		int n;
		cin >> n;
		long long k;
		cin >> k;
		vector<int> vec(n);
		for(auto &a : vec)
			cin >> a;
		
		for(int x =0; x<k; x++){
			vec[x%n] = vec[x%n] ^ vec[n-1 - (x)%n];
			if((x+1)%n == 0){
				for(auto aa : vec) 
					cout << aa << " ";
				cout << endl;
			}
		}
		cout << vec[0];
		for(int x =1; x<n; x++ )
			cout <<" " <<  vec[x];
		cout << endl;
	}
}