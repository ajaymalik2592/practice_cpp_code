#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
// int MAXN = 100000;
// int n, t[400000];
// void build(int a[], int v, int tl, int tr) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = max(t[v*2] , t[v*2+1]);
//     }
// }
// int sum(int v, int tl, int tr, int l, int r) {
//     if (l > r) 
//         return 0;
//     if (l == tl && r == tr) {
//         return t[v];
//     }
//     int tm = (tl + tr) / 2;
//     return max(sum(v*2, tl, tm, l, min(r, tm))
//            , sum(v*2+1, tm+1, tr, max(l, tm+1), r));
// }
// void update(int v, int tl, int tr, int pos, int new_val) {
//     if (tl == tr) {
//         t[v] = new_val;
//     } else {
//         int tm = (tl + tr) / 2;
//         if (pos <= tm)
//             update(v*2, tl, tm, pos, new_val);
//         else
//             update(v*2+1, tm+1, tr, pos, new_val);
//         t[v] = max(t[v*2] , t[v*2+1]);
//     }
// }
int main(){

	
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		ll n , q;

		cin >> n >> q;
		
		ll s = 0;
		set<ll> se;
		while(q--)
		{
			int a;
			cin >> a;
			ll x , y;
			
			if(a == 1)
			{
				
				cin >> x;
				x += s;
				se.insert(x);
			}
			else
			{
				
				cin >> x >> y;
				x +=s;
				y += s;
				ll u = 0;
				auto  R = se.find(y);
				auto L = se.find(x);
			
				
				
				if(u <= x)
					u = y;
				
				s+=u;
				s%=n;
				cout << u << "\n";
			}
		}
	}


}