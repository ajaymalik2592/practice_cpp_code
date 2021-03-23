#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define all(v) v.begin() , v.end()
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
//ll mod =  998244353;
int N;
int count1 = 0;
int r = 0 , g = 0;

vector <int> vec[300005];
int color[300005], num[300005][3], visited[300005]; //parent[300005];
//vector <pair<int,int>> pa(300005 , {0,0});
void dfs(int a)
{
	if(!visited[a])
	{
		visited[a] = 1;
		
		num[a][color[a]]++;
		for(auto x : vec[a])
		{
			if(visited[x])
				continue;
			dfs(x);
			num[a][1] += num[x][1];
			num[a][2] += num[x][2];
			if((r-num[x][1] == 0 || g - num[x][2] == 0 ) && (num[x][2] == 0 || num[x][1] == 0))
					count1++;
		}
	}
}
int main()
	{
			cin >> N;
			F(x,1,N)
			{
				cin >> color[x];
				if(color[x] == 1)r++;
				else if(color[x] == 2)g++;
				}
			F(x,1,N-1)
				{
					int i,j;
					cin >> i >> j;
					vec[i].pb(j);
					vec[j].pb(i);
				}
			dfs(1);
			cout << count1 << "\n";
		}
