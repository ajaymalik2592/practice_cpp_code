#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
 
 vector<int>    t1[100000] , st[100000]; 
stack<int> s ;
 
vector<int> check , visited , par;
void dfs( int b)
{	if(!visited [b-1])
		{	check.pb(b);
			visited[b-1] = true;
			for(auto p : t1[b-1])
			{
				dfs(p);
			}
			check.pb(b);
		}
}
 
int var = 1,t =1;
void   subtree( )
{	
	
	if(! s.empty())
	{   
		 t = s.top();
		//cout<<t<<"\n";
		s.pop();	
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
				if(t!=1)
				var = par[t-1];
				
				
				}
		subtree(   );
		}
	
}
vector<int> c;
ll maa = 0;
void  df(int y , int g   )
{
	if(!visited [y-1])
		{
			visited[y-1] = true;
			if(c[y -1 ] %g==0)maa++;
			//cout<< "ajay "<<y <<" "<<maa<<"\n";
			
			for(auto p : st[y-1])
			{
				df(p , g );
				
				
			}
			
		}
	 
 
	}
 
int main()
{	
	int n,i,j;
	cin>>n;
	
	c.resize(n);
	visited.resize(n);
	for(int x =  0 ; x< n ;x++)
		{	
			cin>>c[x];
		}
	//st.resize(n  );
	//t1.resize(n  );
	//check.resize(2*n);
	for(int x = 0 ; x < n-1 ;x++)
		{
			cin>>i>>j;
			t1[i-1].pb(j);
			t1[j-1].pb(i);
		}
 
	
	dfs(1 );
	
 
	for(int x = 0 ; x< n ; x++)
		visited[x] = false;
	for(auto x1 :check )
		s.push(x1);
	par.resize(n);
	//cout<<"dfs\n";
	subtree(  );
	//for(int x = 0 ; x < n ; x++)cout<<par[x]<<"  \n";
	int q;
	cin>>q;
	int x,y,g;
	while(q--)
	{
		
		cin>>x>>y>>g;
		if(x==1)
		{c[y-1] = g; 
		}
		
		else{
			maa=0;
			for(int l = 0 ;l < n ; l++)visited[l] = false;
			df(y,g);
			
			cout<<(maa*(maa-1))/2<<"\n";
			
		}
}
 
return 0;
 
}
