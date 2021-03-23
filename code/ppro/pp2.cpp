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
	int t;
	cin >> t;
	while(t--)
	{
		ll n , k;
		cin >> n >> k;
		vector <pair <int , int> > vec;
		vec.resize(n);
		int i =1;
		for(auto &a : vec)
			{
				cin >> a.first ;
				a.second = i;
				i++;
			}

		sort(vec.begin() , vec.end());
		vector <int> v;
		int s = vec[0].first, r = 0;
		for(int x = 0 ; x < n ; x++)
		{
			if(s == vec[x].first )
				r++;
			else 
			{
				v.pb(r);
				r = 1;
				s = vec[x].first;
			}
			


		}
		if(r != 0)
			v.pb(r);
	    r = 0 ;
	    ll  re = pow(10,16) , pre = (k*(k-1))/2;
	    bool check = false;
		for(auto d : v)
		{
			//cout << "d "<<d <<"\n";
			if(d < k)
				r += d;
			else
			{
				check = true;
				int x , temp = 0;
				for( x = 0 ;x < k ; x++)
					temp += vec[r + x].second;
				re = min(re , temp - pre - k*vec[r].second );
				//cout << "temp "<< temp << "  pre "<< pre <<" first "<<vec[r].second <<"\n"; 
				for( x = 0 ; x < d - k ; x++ )
				{
					temp =  temp - vec[r + x].second + vec[r + x + k].second;
					re = min(re ,temp - pre - vec[r+x].second*k );
				}
				r += d;
			}
		}

		if(check)
			cout << re << "\n";
		else 
			cout << -1 << "\n";
	}

	}
