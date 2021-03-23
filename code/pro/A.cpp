#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()


ll gcd (ll a , ll b)
{
	if(b==0)
		return a;
	else 
		return gcd(b,a%b);
}
int main()
	{

		int n , k ;
		cin >> n >> k;
		int re = 0 , f = k , pr = 0;
		for(int x = 1 ;x< n - 1  ;x++)
		{
			if(re < n-1)
			{
				pr += f*x;
				f = 1;
			}
			else break;

		}
		cout << pr << "\n";
	}