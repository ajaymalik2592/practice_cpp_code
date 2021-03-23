#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> vec(n+1), v(n+1,1);
	for(int x=1; x<=n; x++)vec[x] = x;
	vector< pair<int, int> > vect;
	for(int x =0;x<m ;x++)
	{
		int t,l,r;
		cin >> t >> l >> r;
		if(t == 1)
		{
			for(int y = l; y< r; y++)v[y] = 1;
		}
		else
		{
			vect.pb({l,r});
		}
	}
	bool po = true;
	sort(vect.begin(), vect.end());
	vector< int > swapings(n+1,0);
	for(auto d : vect)
	{
		
		int l = d.first , r = d.second ;
		int  o = 0;
		for(int x =l; x< r; x++)
			{
				if(v[x] != 1){
					swapings[x] = 1;
					o = 1;
					break;
				}
		}
		if(o == 0)
		{
			cout << "NO";
			return 0 ;
		}
	}
	bool fuck = false;
	int l = n , r;
	for(int x = n-1; x>= 0; x--)
	{
		if( swapings[x] )
		{
			if(!fuck)
				r = x+1, fuck = true;

		}
		else
		{
			if(fuck)
				{
					l = x+1, fuck = false;
			reverse(vec.begin()+l, vec.begin() + r+1);
		}
		}



	}
	fuck = true;
	for(int x =1; x<n; x++)
	{
		if(v[x])
			if(vec[x] > vec[x+1])
				fuck = false;
	}
	if(!fuck )
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int x =1; x<= n; x++)
	{
		cout << vec[x] << " ";
	}
 
}