#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
struct point
{
	int x_top, y_top, x_bottom, y_bottom;
};
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n , m;
		cin >> n >> m;
		vector <string> vec(n, "");
		for(auto &A : vec) 
			cin >> A;
		vector<pair<int, int>>  v[26];
		for(int x =0; x<26; x++)
			v[x].clear();
		vector<int> directions(26, 0);
		for(int x =0; x<n; x++)
		{
			for(int y =0; y<m; y++)
			{
				if(vec[x][y] >= 'a')
					v[vec[x][y] - 'a'].pb({x,y});
			}
		}
		bool r = true;
		int fir =-1;
		for(int x =0; x<26; x++)
		{
			if(v[x].size() >= 1)
			{
				fir = x;
				int X = v[x][0].first , Y = v[x][0].second;
				int flat = 1, upside = 1;
				for(int y =1; y<v[x].size() ; y++)
				{
					if(v[x][y].first != X && v[x][y].second != Y)
						r = false;

					if(v[x][y].first == X)
						flat ++;
					if(v[x][y].second == Y)
					    upside++;
				}
				if(flat != v[x].size() && upside != v[x].size())
					r = false;
				if(upside == v[x].size())
					directions[x] = 1;
			}

		}
		struct point po [fir + 1];
		for(int x =0; x<= fir ; x++)
		{
			if(v[x].size() >= 1)
			{
				po[x].x_top = v[x][0].first;
				po[x].y_top = v[x][0].second;
				po[x].x_bottom = v[x][v[x].size() - 1].first;
				po[x].y_bottom = v[x][v[x].size() - 1].second;
			}
			else
			{
				po[x].x_top = v[fir][0].first;
				po[x].y_top = v[fir][0].second;
				po[x].x_bottom = v[fir][v[fir].size() - 1].first;
				po[x].y_bottom = v[fir][v[fir].size() - 1].second;
			}
		}
		// if(r)cout <<"aghhfhf";
		for(int x =0; x<fir+ 1; x++)
		{
			// cout << directions[x] << " " << po[x].x_top << " " << po[x].y_top << " " << po[x].x_bottom << " " << po[x].y_bottom << "\n";
			if(directions[x] == 0)
			{
				for(int xx = po[x].y_top ; xx <= po[x].y_bottom; xx++)
				{
					if(vec[po[x].x_top][xx]  < 'a' + x)r = false;
				}
			}
			else
			{

				for(int xx = po[x].x_top ; xx <= po[x].x_bottom; xx++)
				{
					// cout << xx << " " << vec[po[x].y_top][xx] << " " << 'a' + x << " " << r << "\n";
					if(vec[xx][po[x].y_top]  < 'a' + x)r = false;
				}
			}
			// cout << r << "\n";
		}
		if(r)
		{
			cout << "YES\n";
			cout << fir + 1 << "\n";
			for(int x =0; x<fir + 1; x++)
			{
				cout << po[x].x_top + 1 << " " << po[x].y_top + 1 << " " << po[x].x_bottom  + 1<< " "<< po[x].y_bottom + 1<<"\n";
			}
		}
		else
			cout << "NO" << "\n";

	}
}