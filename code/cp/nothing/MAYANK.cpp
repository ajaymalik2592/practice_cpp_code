#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n,k;
		cin >> n >> k;
		vector<pair<long long , int>> vec(n);
		for(int x =0; x<n; x++)
		{
			cin >> vec[x].first;
			vec[x].second = x;
		}
		sort(vec.begin(), vec.end());
		vector<int> win(n, 0), s(n+5, 0);
		int j =0;
		long long sum = 0;
		for(int x =0; x<n; x++)
		{
			if(x < j)s[vec[x].second ] = 1;
			long long have = k * (j ) + vec[x].first - sum;
			while(j < n )
			{
				if(x ==  j){
					s[vec[j].second] = 1;
					sum += vec[j].first;
					j++;
					continue;
				}
				if(have <= vec[j].first){
					break;
				}else
				{
					have += k - vec[j].first;
				}

				sum += vec[j].first;
				
				j++;

			}
			// if(win[vec[x].second] == -2)win[vec[x].second ] = 0;
			win[vec[x].second ] += j - s[vec[x].second];
			
		}
		for(auto a : win)cout << a << " ";
		cout << "\n";
	}
}