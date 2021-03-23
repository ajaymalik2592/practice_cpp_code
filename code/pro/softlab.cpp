#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(x,a,b) for(int x = (int)a ; x  <= int(b) ; x++)
int visited[100001];
struct book
{
	int nod;
	int weight;
};
typedef struct book val;

ll cost;

 df(vector < val > node [] , int d , int visited [] , int f )
{
	if (f <= d && visited[d] == -1 )
	{ cost++;
		for(int y = 0 ; y < node[d].size() ; y++ )
		{	
			int no  = node[d][y].nod , we = node[d][y].weight;
			 df(node , no , visited , f + we);
		}
	}
	
	


int main()
{
	int n;
	cin>>n;
	
	F(x,0,n)
	{
		visited[x] = -1 ;
	}

	vector < val > node[n];  

	int d[n+1];

	F(x,1,n)
	{
		cin>>d[x];
	}

	int i, j ,p;
	F(x,1,n-1)
	{
		cin >> i >> j >> p ;
		node[i].nod = j;
		node[i].weight = p;
		node[j].nod = i;
		node[j].nod = p;
	}

	for(int x =1 ; x <= n ; x++)
	{
		cost = 0;

		 df(node , d[x] , visited , (ll)0 );

		 cout << cost <<" ";
		 for(int y = 1 ; y< n+1 ; y++)
		 	visited[y]  = -1;

	}
	return 0;
}