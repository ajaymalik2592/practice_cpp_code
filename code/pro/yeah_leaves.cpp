#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define ALL(v) v.begin(), v.end()
int main()
{
	
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);
	long long k ;
	cin >> k ;
	int test;
	cin >> test;
	for(int test_cases = 1; test_cases<=test; test_cases++)
	{
		ll n,m, ans;
		cin >> n >> m;
		if(n == 1 || n == 3)
			ans = m;
		else if(n == 2)
			ans  = -1;
		else
		{
			vector<int> vec = {2, 0, 0}, vec1 = {2, 0 , 0}, vec2 = {2, 0, 0}, index = {2,0,1};
			// if(m == 2)vec[2] = 1, vec1[2] = 1;
			for(int y =4; y<= n; y++)
			{
				for(int g =0; g<3; g++)vec1[x] = vec2[g];
				int need = y / k, available = m;
				for(int x=0;x<3; x++)
				{
					int u = index[x];

					if(need == 0)
					{

						vec2[0] += vec[x];
						vec1[x] = 0;
						continue; 
					}
					if(need >= vec[u])
					{
						need -= vec[u];
						available -= vec[u] * ((u == 2)? 0 : (u+1));
						vec2[u] -= vec[u];
						if(u != 1)
						vec2[(u+1)%3] += vec[u];
						else vec2[0] += vec[u];

					}
					else
					{
						if(u != 1)
						vec2[(u+1)%3] += need;

						vec2[u] -= need;

						vec2[0] += vec1[u];
						
						available -= need * (u == 2? 0 : (u+1));
						need = 0;
					}
					


				}
				if(available >= 0 && need == 0)
				{
					if(ans >= 2)vec1[0]++;
					ans = available;
					for(int x =0; x<3; x++)vec[x] = vec1[x];
					if(ans < 2)vec[ans] ++, vec1[ans]++;
					vec[2] = vec1[2] = 0;

				}
				else
				{
					ans = -1;
					vec[2]++;
					for(int x =0; x<3; x++) vec1[x] = vec[x];
				}
			}

		}
		if(ans == -1)
			cout << "Thrown off the roof.";
		else
			cout << ans;
		
		cout << "\n";




	}
}
