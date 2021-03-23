#include<bits/stdc++.h>
using namespace std;
vector<int, int> vec[400005], edge[400005];
int low[100], to[100], visited[100];
int timer = 0;
vector<int>bridge(400005);
void dfs(int a, int pa)
{
	visited[a] = 1;
	low[a] = to[a] = timer++;
	for(int b : vec[a])
	{
		if(b.first == pa)continue;
		if(visited[b.first])
			low[a] = min(low[b.first], to[a]);
		else
		{
			dfs(b.first,a);
			low[a] = min(low[a], low[b.first]);
			if(low[b.first] > to[a])
			{
				bridge[b.second] = 1;
			}
		}
	}

}
int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;

	for(int x =0; x<m; x++)
	{
		int i,j;
		cin >> i >> j;
		vec[--i].push_back({--j, x});
		vec[j].push_back({i, x } );
	}
	dfs(0,-1);
	for(auto )
	// for(auto a : bridge)
	// 	{
	// 		cout << a.first  +1 << " " << a.second  + 1<< endl;
	// }
	return 0;
}