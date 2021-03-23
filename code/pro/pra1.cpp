#include<bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(), v.end()
typedef long long ll;
#define speed ios_base::sync_with_stdio(NULL);cin.tie(NULl);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
int main()
{
	
	ll n;
	cin >> n;
	vector<ll> vec(n);
	for(auto &t : vec)
		cin >> t,t = abs(t);
	sort(ALL(vec));
	ll s = 0;
	for(int x=0;x <n;x++)
	{
		s += ub(vec,2*(abs(vec[x]))) - x - 1;
	}
	cout << s;

}