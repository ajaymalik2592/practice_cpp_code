#include<bits/stdc++.h>
using namespace std;
#define F(x,a,b) for(int x = (int)a ; x <= (int)b ; x++)
int main()
{
	int n,m;
	cin>>n>>m;
	
	int a[n];
	F(x,0,n-1)cin>>a[x];
	
	pair<int , int > query[m] ;
	F(x,0,m-1)cin>>query[x].first>>query[x].second;
	
	int vec[n][n];
	//vector<int> index(n, 0);
	
	F(x,0,n-1)F(y,0,n-1)vec[x][y] = 0 ;
	
	F(x,0,n-1)
	{
		F(y,0,m-1)
		{	if(x+1 < query[y].first  ||  x+1 > query[y].second)
			F(z,query[y].first -1,query[y].second)vec[x][z]++;
		}
		F(y,0,n-1)cout<<"x  : y  "<<x+1 << "  "<< y+1 << "   "<<vec[x][y]<<"\n";

		
		int j = 0;
		F(y,1,n-1){if(vec[x][j] < vec[x][y]) j = y;}
		vec[x][x] = a[x] + vec[x][j];
	}
	
	int j = 0;
	F(x,1,n-1)
	{	//cout<<"ajay malik not sleepy"<<"\n";
		if(vec[x][x] > vec[j][j])j =x;
	}
	int index = 0;
	cout<<vec[j][j]<<"\n";
	F(x,0,m-1){	
				if(query[x].first > j+1 ||  j+1  > query[x].second)
					index++;
			}
	cout<<index<<"\n";
	F(z,0,m-1)
		if(query[z].first > j+1 ||  j+1  > query[z].second)
			cout<<z+1<<" ";
	cout<<"\n";

	return 0;
}
