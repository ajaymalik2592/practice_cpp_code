#include<bits/stdc++.h>
using namespace std;
#define INF 100000000007.10202
int main()
{
	
	int n;
	cin >> n;
	vector <pair <long long  double,long long  double>> pa(n);
	for(auto &y : pa)
		cin >> y.first  >> y.second;

	map< long long  double , set < long long  double > >  ma;
	for(int x= 0;x <n; x++)
	{
		for(int y =x +1; y < n; y++)
		{
			long long  double m, i ;
			if(pa[x].first == pa[y].first)
				ma[INF].insert(pa[x].first);
			else
			{
				m = pa[y].second - pa[x].second ;
				m/= pa[y].first - pa[x].first;
				if(pa[x].second == pa[y].second)
					ma[m].insert(pa[x].second);
				else

				ma[m].insert(pa[x].first  - pa[x].second / m );
			}
		}
	}
	

	long long  x1 = 0, x2 = 0;

	for(auto r : ma)
	{
	
	  long long j = r.second.size();
	  x1 += j;
	  x2 += j * (j -1) / 2;
	}
	cout << (x1 * (x1 - 1) / 2) - x2 ;
}