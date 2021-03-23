#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool go(ll a)
{
	int re = 0;
	while(a)
	{
		re += a % 10;
		a /= 10;
	}
	if(re % 10 == 0)
		return true;
	else
		return false;
}
int main()
	{
		
		int t;
		cin >> t;
		while(t--)
		{
			ll n;
			cin >> n;
			int r = 0, sum ;
			for(ll v = 18; v < 100000000; v++)
			{
				if(go(v))
					r++;
				if(r == n)
				{
					sum = v;
					break;
				}
			}
			cout << sum << "\n";
		}
        

	}
