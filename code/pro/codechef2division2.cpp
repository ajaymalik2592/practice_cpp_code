#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

int main()
	{
		
		speed
		int t ; 
		cin >> t ;
		while(t--)
		{
			int n;
			cin >> n;
			int a [n];
			F(x,0,n-1)cin>>a[x];
			ll su = -1 ,temp;
			F(x,0,n-1){
				cin >> temp;
				int l = x - 1 , r = x +1;
				l = (l + n )%n  , r = (r +n )%n ;
				if(temp > a[l] + a[r])
					su = max(su , temp);

			}
			cout << su <<"\n";
		}

		return 0;
	}