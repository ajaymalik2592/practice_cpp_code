#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()



int main()
	{
		speed
		int t;
		cin >> t;
		for(int index = 1; index <= t ; index ++)
		{
			int n,r,c,p1,p2;
			cin >> n >> r >> c >> p1 >> p2;
			set<pair<int,int>> pa;
			pa.insert(make_pair(p1,p2));
			for(int x=0;x<n;x++)
			{
				char c;
				cin >> c;
				if(c == 'E')
				{
					p2++;
					pair<int,int> po;
					po.first = p1;
					po.second = p2;
					while(pa.find(po) != pa.end())
					{
						p2 ++;
						po.second = p2;
					}
					

				}
				else if(c == 'W')
				{
					p2--;
					pair<int,int> po;
					po.first = p1;
					po.second = p2;
					while(pa.find(po) != pa.end())
					{
						p2--;
						po.second = p2;
					}
					
				}
				else if(c == 'N')
				{
					p1--;
					pair<int,int> po;
					po.first = p1;
					po.second = p2;
					while(pa.find(po) != pa.end())
					{
						p1--;
						po.first = p1;
					}

					
				}
				else
				{
					p1++;
					pair<int,int> po;
					po.first = p1;
					po.second = p2;
					while(pa.find(po) != pa.end())
					{
						p1++;
						po.first = p1;
					}
				}
				pa.insert(make_pair(p1,p2));
			}
			cout <<"Case #" << index << ": " <<  p1 << " " << p2 << endl;


	}

}
/*


int t;
		cin >> t;
		for(int test_case =1; test_case <= t; test_case ++)
		{
			int n,k;
			cin >> n >> k;
			map<int, vector<int>> ma;
			vector<int> position(n), color(n);
			for(auto &value : position)
				cin >> value;
			for(auto &value : color)
				cin >> value;
			for(int x=0; x<n;x++)
			{
				ma[color[x]].pb(position[x]);
			}
			priority_queue< pair<int , int>  > que;
			for(auto &val : ma)
			{
				sort(ALL(val.second));
			}
			for(auto val : ma)
			{
				int col = val.first;
				vector<int> vec = val.second;
				int total = 0;
				for(auto re : vec)
				{
					total  += re;
					priority_queue.push(make_pair(total, col));
				}
			}
			int ans = calculate(required, n, k, 0);
			cout << "Case #" << test_case << ": " << ans << "\n";
		}

			vector<int> position(n), color(n);
			for(auto &value : position)
				cin >> value;
			for(auto &value : color)
				cin >> value;
			vector < pair<int, int> > required(n);
			for(int x = 0; x <n; x++)
			{
				required[x].first = position[x];
				required[x].second = color[x];
			}
			sort(ALL(required));




*/