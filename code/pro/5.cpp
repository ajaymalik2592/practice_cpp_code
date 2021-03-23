#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long unsigned ull;
template<typename t> t powe(t a , t b , t c){t re =1 ; while(b){if(b%2==1) re*=a, re%c;a*=a,a%=c, b>>=1;}return re;}
ll gcd(ll a , ll b)
{if(b==0)return a;
	else return gcd(b,a%b);
	}
vector <vector<ll> >  t1 , st; 
bool visited[7] = {false,false,false,false,false,false,false};
vector<ll>check;
void dfs( ll b)
{	if(!visited [b-1])
		{	check.pb(b);
			visited[b-1] = true;
			for(ll p : t1[b-1])
			{
				dfs(p);
			}
			check.pb(b);
		}
}

ll var , temp;
void   subtree(stack < ll > sta , vector<ll > par  )
{	
	
	if(! sta.empty())
	{   
		ll t = sta.top();
		//cout<<t<<"\n";
		sta.pop();	
		if(!visited[t-1])
		{	
			visited[t-1] = true;
			
			 
			  if(t != var  )
				{
					st[var -1].pb(t);
					par[t-1] = var; 
				}
			
			var = t;
			
			
			}
		else{
				
				var = par[t-1];
				
				
				}
		subtree( sta , par );
		}
	
}


	

int main()
{ 
	ll n;
	cin>>n;
	vector < vector < ll> > aa(n , vector<ll>() );
	vector<ll> hir(n , n+1);
	hir[0] = 1;
	
	vector<ll> c;
	c.resize(n);
	for(ll x = 0; x <= n-1; x++)cin>>c[x];

	int u,v;
	for(int x = 0;x< n-1 ;x++)
	{
		cin>>u>>v;
		if(u  < v)
		aa[u-1] .push_back(v);
		else aa[v-1].push_back(u);
		//aa[v-1].push_back(u);
		}
		
	int p = 1;
	queue<ll> que ;
	vector<ll> ch;
	que.append(1);
	while(que.empty() == false)
	
	{ int e = que.top();
		que.pop();
		if(hir[e-1])
		hir[e-1] = p;
		
		
		}
		ll tt;
		cin>>tt;
	while(tt--)
	{
			int x , y,q1;
			cin>>q1>>x>>y;
			if(q1 ==1)c[x-1] = y;
			else{
				ll su = 0;
				int ss =aa[x-1].size();
			for(int j = 0 ; j < ss ; j++)
				{
					if(gcd(c[x-1] , c[aa[x-1][j] -1]) %y == 0)su++;}
					
				
			
			for(int j = 0 ; j < ss-1 ; j++)
				{
					for(int k = j+1 ; k < ss ; k++)
					if( (gcd( c[aa[x-1][k] -1], c[aa[x-1][j] -1])) % y == 0)su++;}
					
					cout<<su<<endl;
				}
			}
			
				
	
	return 0;
}
