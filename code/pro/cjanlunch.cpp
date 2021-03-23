#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
long double PI = 3.1415926535897;

int main()
	{
		long double r , R;
		long double n;
		cin>>n>>r;
		long double e = sin(PI / n);
		R = r*(e/ (1-e));
		cout<<fixed;
		cout<<setprecision(18)<<R<<"\n";
		
		return 0;
 
	}

