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
		
		ll n;
		cin >> n;
		vector<ll> vec(n-1);
		for(auto &a : vec)
			cin >> a;
		bool r = false;
		int f;
		cin >> f;
		long long de = 1e18, in = 0;
		for(int x =0; x<n-1;x++)
		{
			if(vec[x] > f)continue;
			r = true;
			int index = 0;
			
			long long val = 0;
			bool poo = false;
			if(x%2 == 1)
				val += vec[x-1], poo = true;
			int j = n-1 - x/2 ;
			int h = log2(j);
			j -= int(pow(2,h));
			int o = 1;
			bool kakku = false;
			int o1 = 1;
			int pop = 0;
			while(h)
			{
				o*=2;

				h--;

				if(j%o == 1)
				{
					if(!pop)
						kakku = true;
					else
						kakku = false;
					pop = 1;
					
				}
				else
				{
					pop = 0;

				}
				
				if(!kakku)
					continue;
				o1 = j % o;
				if(o1 <= x/2 + poo)
				{
					int p = x - o1*2 ;
					if(poo)p++;

					
					val += vec[p];
				}
				else
				{
					int p = x/2 -o1 + poo;
					p = (p + n -1 )%(n-1);

					val += vec[p];

				}
			}
			if(val + f  < de)
				de = val + f , in = x;

		}
		if(r)
		{
			cout << "possible\n";
			cout << in + 1 << " " << de;
		}
		else
		{
			cout << "impossible";
		}
		cout << "\n";
		
	}
}
