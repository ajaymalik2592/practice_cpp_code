#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
int a[51][51] , visited[51][51];
int n;
vector <pair <int , int>>  from, dest;
void check(int a[51][51] , int visited[51][51] , int x ,int y , int p)
{
	if(x >=1 && x <= n && y >= 1 && y <= n && a[x][y] == 0 && !visited[x][y] )
	{
		if(p == 0)
			from.push_back(make_pair(x,y));
		else
			dest.push_back(make_pair(x,y));
		visited[x][y] = 1;
		//check(a,visited,x-1,y-1 ,p);
		check(a,visited,x-1,y,p);
		//check(a,visited,x-1,y+1,p);
		check(a,visited,x,y-1,p);
		check(a,visited,x,y+1,p);
		//check(a,visited,x+1,y-1,p);
		check(a,visited,x+1,y,p);
		//check(a,visited,x+1,y+1,p);
	
	}
}
int main()
{

	speed
	
	cin >> n;
	int  x1, y1, x2, y2;
	
	cin >> x1 >> y1 >> x2 >> y2;
	for(int x = 1 ;x<  n +1 ; x++)
	{
		for(int y =1 ; y <n+1 ;y++)
		{
			char c;
			cin >> c;
			if(c=='0')
				a[x][y] = 0;
			else 
				a[x][y] = 1;
			visited[x][y] = 0;
		}
	}
	check(a , visited , x1,y1,0);
	if(visited[x2][y2 ] == 1)
		cout << 0<<"\n";
	else
	{
		check(a,visited,x2,y2,1);
		int w = 100000000;
		for(auto s :from)
		{
			for(auto p : dest)
			{
				w = min (w , abs(s.first - p.first)*abs(s.first - p.first) + abs(s.second - p.second)*abs(s.second - p.second) );
			}
		}
		cout << w <<"\n";
	}



}

