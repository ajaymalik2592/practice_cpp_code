#include<bits/stdc++.h>
using namespace std;
#define F(x,a,b) for(int x = (int)a;  x<=b ; x++)
 int cost = 1000000;
int tsp(vector< vector <int > > a ,vector<int> a1[], int s ,int d )
{	
	if(s == d )return 0;
	for(auto x : a1[s-1])
	{	
		a[s-1][d-1] = min (tsp(a ,a1, x , d ) +  a[s-1][ x-1] , a[s-1][d-1]  )   ;
		
		cout<<" from "<< s <<" to "<<d<<"  is "<<a[s-1][d-1]<<"\n";
	}
	return a[s-1][d-1];
}
int main()
{
	int n,i,j,tempcost;
	cout<<"enter the number of vertices \n";
	cin>>n;

	cout<<"enter the edges with cost \n";
	 vector <vector<int > > vec (n , vector< int > (n , -1));
	 vector<int> a[n];
	F(x,0,n-1)F(y,0,n-1){if(x==y) vec[x][y] = 0;
		else vec[x][y] = 1000000;}
	int e;
	cout<<"enter the number of edges \n";

	cin>>e;
	//F(x,0,n-1)F(y,0,n-1){cout<<x+1<<" "<<y+1<< "  "<<vec[x][y]<<"\n" ;}
	F(x,0,e-1)
	{
		cin>>i>>j>>tempcost;
		a[i-1].push_back(j);
		vec[i-1][j-1] = tempcost;
	}


	int finalcost = tsp(vec,a , 1 , n);
	cout<<"minimum cost from 1 to "<<n<<" is "<<finalcost<<"\n";


	return 0;
}
