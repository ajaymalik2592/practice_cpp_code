#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define all(v) v.begin() , v.end()
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

int main()
{
	int n;
	cin >> n;
	// vector <ll >vec;
	ll su = 0 , re = 0 , f = 0 , s = 0 , count = 0 , vec[3];
	F(x,1,n)
	{
		ll i;
		cin >> i;
		if(i >= 0)
			re += i;
		else
		{
			if(count == 0)
			{
				vec[0] = i;
				re -= i;
				count ++;

			}
			else if(count ==1) 
			{
				count ++;
				vec[1] = i;
				re += -1 * i;
				sort(vec , vec+2);
			}
			else
			{
				if(i <= vec[1] && vec[0] >= i)
				{
					re += -1*i + 2*vec[1];
					vec[1] = vec[0];
					vec[0] = i;
					
				}
				else if(vec[0] < i && vec[1] >= i )
				{
					re += 2*vec[1] - 1*i;
					vec[1] = i;

				}
				else 
				{
					re += i;
				}
			}
		}
		su = max(su , re);
		re = max(0LL,re);
	}
	cout << su << endl;
}