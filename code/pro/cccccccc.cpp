#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ALL(v) v.begin(), v.end()
int main()
{
	int test;
	cin >> test;
	for(int test_cases = 1; test_cases<=test; test_cases++)
	{
		long long n, z;
		cin >> n >> z;
		vector<long long> vec(n);
		long long  s =1e18; 
		for(auto &a : vec)
			cin >> a;
		sort(ALL(vec));
		reverse(ALL(vec));
		vector<long long> su(n+2, 0);
		for(int x =1; x<=n; x++)
			su[x] = su[x-1] + vec[x-1];
		// for(long long  x =0; x<=n-z; x++)
		// {
		// 	long long s1 = 1e18, taken = 0, in = x;
		// 	for(int y = 0; y<z; y++)
		// 	{
		// 		int u = z + x - y;
		// 		s1 = min(su[y+1] + su[u] - su[x+1+y] + (z-y-1)*vec[x+y] , s1 );
		// 		cout << x << " x " << y << " " << s1 << endl;

		// 	}
		// 	// for(int y =0; y<=x; y++)
		// 	// {
		// 	// 	s1 = min(s1 , vec[y]* y + su[y+z]- su[y+1]);
		// 	// 	cout << x << " x " << y << " " << s1 << endl;

		// 	// }

		// 	s = min(s1 , s);
		// }
		vector<int> vov(n,0);
		for(int x =n-1; x>= n-z; x--)
			vov[x] = 1;

		do
		{
			long long s1 = 0, h = 0;
			for(int x =0; x<n; x++)
			{
				if(vov[x] == 0)h++;
				else
				{
					s1 += (h+1)* (vec[x]);
					h=0;
				}
			}
			
			s = min(s, s1);
			
		}while(next_permutation(ALL(vov)));
		cout << s << endl;
	}
}
