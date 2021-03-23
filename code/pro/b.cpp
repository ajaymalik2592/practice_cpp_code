#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
bool used[100001];
int  level , temp , temp1 , n ;
void bfs(queue< pair< int , int > > q , vector<  int >  adj[]  , int k  )
{
	while (!q.empty()) 
	{
		
		pair< int , int > v = q.front();
		if(n - temp < k) break;
		if(n - temp >= k && level < v.second) 
			level = v.second;
		//cout << "v.first " << v.first << "  v.second  " << v.second<<"  temp  "<<temp <<"\n";  
		q.pop();

		for (int u : adj[v.first]  ) 
		{


				if(!used[u])
				{

		    	
		        used[u] = true;
		        q.push(make_pair(u,v.second +1));
		        temp++;
		    	}
		}
	}
}

int main()
	{

		speed
		
		cin >> n;
		int k[n+1];
		F(x,1,n)
			cin >> k[x];
		int i , j ;
		vector < int > vec[n+1];
		F(x,0,n-2)
		{
			cin >> i >> j;
			vec[i].pb(j);
			vec[j].pb(i);
		} 
		
		queue < pair < int , int >  > que;
		F(x,1,n)
		{	while(!que.empty())que.pop();
			que.push(make_pair(x,0) );
			for(int xx = 1 ; xx < n + 1 ; xx++)used[xx] = false;
			
			level = 0;
			temp = 1 ;
			temp1  = 0;
			used[x] = true;
			bfs(que , vec , k[x]);
			cout << level << " ";




		}


		return 0;
	}