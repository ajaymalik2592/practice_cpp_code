#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
ll mod = 1e9 + 7;
int summ(pair<int, int> a)
{
	return a.first + a.second;
} 
bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	if(a.first != b.first)
		return a.first > b.first;
	else
		return summ(a.second) < summ(b.second);
}
bool common(pair<int, vector< pair < int, int>> > a, pair<int, vector< pair < int, int>> > b)
{
	return a.first < b.first;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> vec[n];
	vector<pair < int, pair<int, int>> > pa;
	int i = 1, j;
	for(auto &a : vec)
	{
		a.resize(m);
		 j = 1;
		for(auto &b : a)
		{
			cin >> b;
			pa.pb({b, {i, j}});
			j++;
		}
		i++;
	}
	sort(pa.begin(), pa.end(), comp);
	int f = -1, u = -1;
	// for(auto &s : pa)
	// {
	// 	if(s.first != f)
	// 	{
	// 		f = s.first;
	// 		u++;
	// 	}
	// 	s.first = u;
	// 	vec[s.second.first -1][s.second.second -1] = u;
	// }
	// cout << "ajay\n";
	// for(auto s : vec)
	// {
	// 	for(auto f : s)
	// 		cout << f << " ";
	// 	cout << "\n";
	// }
	u = 0;
	int step = n*m+3;
	 vector< pair<int , vector<pair<int, int>>> > zer(step);
	for(int x = 0; x<step; x++)zer[x].first = 0;
	vector<int> v(step, vec[0][0]);
	int d = 0;
	for(auto a: pa)
	{
		if(d >= min(110, step - 3))
			break;
		i = a.second.first, j = a.second.second;
		if(j%2 && i != n)
		{
			
			// cout << " value " << a.first << " " << i << " " << j  <<"\n";
			for(int x = 1; x<=j; x++)
			{
				if(vec[0][x-1] > v[d])
				{
					v[d] = vec[0][x-1];
					zer[d].first++;
				}
				zer[d].second.pb({1, x});
			}
			for(int x = 2; x <= n-1; x++)
			{

				if(vec[x-1][j-1] > v[d])
				{
					v[d] = vec[x-1][j-1];
					zer[d].first++;
				}
				zer[d].second.pb({x, j});
			}
			for(int x = j-1; x>=1; x--)
			{
				if(x%2 == 0)
				{
					for(int y = n-1; y>= 2; y--)
					{

						if(vec[y-1][x-1] > v[d])
						{
							v[d] = vec[y-1][x-1];
							zer[d].first++;
						}
						zer[d].second.pb({y , x});
					}

				}
				else
				{
					for(int y = 2; y<=n-1;y++)
					{
						if(vec[y-1][x-1] > v[d])
						{
							v[d] = vec[y-1][x-1];
							zer[d].first++;
						}
						zer[d].second.pb({y, x});
					}
				}
			}
			for(int x = 1; x<= j; x++)
			{
				if(vec[n-1][x-1] > v[d])
						{
							v[d] = vec[n-1][x-1];
							zer[d].first++;
						}
				zer[d].second.pb({n,x});
			}
			for(int x = j+1; x<=m; x++)
			{
				if(x%2 == 0)
				{
					for(int y = n; y>= 1; y--)
					{
						if(vec[y-1][x-1] > v[d])
						{
							v[d] = vec[y-1][x-1];
							zer[d].first++;
						}
						zer[d].second.pb({y, x});
					}
				}
				else
				{
					for(int y = 1; y<= n; y++)
					{
						if(vec[y-1][x-1] > v[d])
						{
							v[d] = vec[y-1][x-1];
							zer[d].first++;
						}
						zer[d].second.pb({y ,x});
					}
				}
			}
			// for(auto s : zer)
			// {
			// 	cout << s.first <<  " " << s.second <<"\n";

			// }
			d++;

			// return 0;
		}
	}


	
	// revolve[0][0] = 0, revolve[0][1] = vec[0][0];
	// revolve[1][0] = 0, revolve[1][1] = vec[1][0];
	
	for(int x =1; x<=m; x++)
	{
		if(x %2 == 0)
		{
			for(int y = n; y>= 1; y--)
			{
			    if(vec[y-1][x-1] > v[d])
			    {
			       	zer[d].first++;
			       	v[d] = vec[y-1][x-1];
			    }
			    zer[d].second.pb({y,x});
				// cout << y <<" " <<  x <<"\n";
			}

		}
		else
		{
			for(int y =1; y<= n; y++)
			{
			 if(vec[y-1][x-1] >v[d])
			    {
			        zer[d].first++;
			       	v[d] = vec[y-1][x-1];
			    }
			  zer[d].second.pb({y,x});

			}
		}
	}
	d++;
	for(int x =1; x<=n; x++)
	{
		if(x %2 == 0)
		{
			for(int y = m; y>= 1; y--)
			{
			    if(vec[x-1][y-1] > v[d])
			    {
			       zer[d].first++;
			       v[d] = vec[x-1][y-1];
			    }
			  	zer[d].second.pb({x,y});

				// cout << y <<" " <<  x <<"\n";
			}

		}
		else
		{
			for(int y =1; y<= m; y++)
			{
			  if(vec[x-1][y-1] > v[d])
			    {
			       zer[d].first++;
			       v[d] = vec[x-1][y-1];
			    }
			  	zer[d].second.pb({x,y});
			}
		}
	}
	d++;
	for(int x = 1; x <= n/2 ; x++)
	{
		if(x > m/2)
		{
			break;
		}
		int y = x;
		for(y; y<= m+1-x; y++)
		{
			 if(vec[x-1][y-1] > v[d])
			    {
			       zer[d].first++;
			       v[d] = vec[x-1][y-1];
			    }
			  	zer[d].second.pb({x,y});

		}
		y--;
		int z = x +1;
		for(z; z<= n+1-x; z++)
		{
			 if(vec[z-1][y-1] > v[d])
			    {
			       zer[d].first++;
			       v[d] = vec[z-1][y-1];
			    }
			  	zer[d].second.pb({z,y});
		}
		y--;
		z--;
		for(y ; y>= x; y--)
		{
			 if(vec[z-1][y-1] > v[d])
			    {
			       zer[d].first++;
			       v[d] = vec[z-1][y-1];
			    }
			  	zer[d].second.pb({z,y});
		}
		z--;
		y++;
		for(z; z> x; z--)
		{
			 if(vec[z-1][y-1] > v[d])
			    {
			       zer[d].first++;
			       v[d] = vec[z-1][y-1];
			    }
			  	zer[d].second.pb({z,y});
		}
	}
	if(n%2 && n <= m)
		for(int y = n/2 +1; y<= m- n/2; y++)
		{
			 if(vec[n/2][y-1] > v[d])
			    {
			       zer[d].first++;
			       v[d] = vec[n/2][y-1];
			    }
			  	zer[d].second.pb({n/2+1,y});
		}
	else if(m%2 && n >= m)
	{
		for(int x = m/2 +1; x<= n-m/2; x++)
		{
			if(v[d] < vec[x-1][m/2 ])
			{
				v[d] = vec[x-1][m/2];
				zer[d].first++;
			}
			zer[d].second.pb({x, m/2+1});
		}
	}
d++;
	// for(auto a : points[2])
	// {
	// 	cout << a.first << " " << a.second << "\n";
	// }
	// cout << "break;";

	// if(revolve[0][0] < revolve[1][0] )
	// {
	//     for(int x =1; x<=m; x++)
 //    	{
 //    		if(x %2 == 0)
 //    		{
 //    			for(int y = n; y>= 1; y--)
 //    			{
    			    
 //    				cout << y <<" " <<  x <<"\n";
 //    			}
    
 //    		}
 //    		else
 //    		{
 //    			for(int y =1; y<= n; y++)
 //    			{
 //    			 cout << y << " " << x << "\n";
 //    			}
 //    		}
 //    	}
	// }
	// else
	// {
	//     for(int x =1; x<=n; x++)
 //    	{
 //    		if(x %2 == 0)
 //    		{
 //    			for(int y = m; y>= 1; y--)
 //    			{
    			   
 //    				cout << x <<" " <<  y <<"\n";
 //    			}
    
 //    		}
 //    		else
 //    		{
 //    			for(int y =1; y<= m; y++)
 //    			{
 //    			 cout << x << " " << y << "\n";
 //    			}
 //    		}
 //    	}
	// }
	
	// for(int x =0 ; x<3; x++)
	// {
	// 	cout << " x " << x << " " << revolve[x][0] << " " << revolve[x][1] << "\n";
	// }
	u = 0;
	for(int x = 1; x<d; x++)
	{
		if(zer[u].first > zer[x].first)
			u = x;
	}
	for(auto fuck : zer[u].second)
	{
		cout << fuck.first << " " << fuck.second << "\n";
	}


}