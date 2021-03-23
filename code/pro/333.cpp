#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define mk make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()

int main()
	{
		int n,t;
		cin >> t ;
		while(t--)
		{
			cin >> n;
			int a[n];
			int re = 0;
			bool check = true;
			for(auto &f : a)
				{
					cin >> f;
					if(f < re || f > re + 1) check = false;
					re = max(re , f);
				}
			if(check && re < 27)
			{
				int m=0;
				for(auto &d : a)
				{
					if(m ==0)cout << "a";
					else
					{
						if(a[m] > a[m-1])cout << char('a' + d -1);
						else cout << 'a';
					}
				m++;
				}
			}
			else
			{
				cout << -1 ;
			}
			cout << "\n";
		
	}
}
