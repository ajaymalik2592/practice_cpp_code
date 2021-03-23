#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()

int main()
	{
		speed
		
		int n, k;
		cin >> n >> k;
		int win = 2*k +1, re = n % win;
		
		cout << ceil(n / float(win)) << endl;
		int e;
		if(re > 0 && re <= k) e = 1;
		else e = k+1;
		for(e;e < n+1 ; e += win )
			cout << e << " ";
	}
