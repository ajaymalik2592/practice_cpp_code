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
ll power(ll a , ll b , ll c)
{
	ll re  =1 ;
	while(b)
	{
		if(b&1)
		{
			re*=a;
			re%=c;
		}
		a*=a;
		a%=c;
		b>>=1;
	}
	return re;
}

ll mod =  998244353;
int main()
	{
		//cout << power((ll)3,(ll)100000,mod) << "\n";
		speed
		int t ;
		cin >> t;
		while(t--)
		{
			//cout << "input " << t <<" ";
			ll n, m;
			cin >> n >> m;
			

			vector <ll> edge[n+1] , visited(n+1,0), color(n+1,0) ;
			F(x,1,m)
			{
				ll i , j;
				cin >> i >> j;
				edge[i].pb(j);
				edge[j].pb(i);
			}
			
			bool check = true;
			//color[1] = 0;
			//depth.pb(1);
			ll finall = 1;
			ll comp = 0;
			for(int x =1 ; x<= n ;x++)
			{
				if(visited[x] == 1)
					{
						continue;
					}
				comp ++;
				//que.clear();
				color[x] = 0;
				vector <ll> depth;
				queue<pair<ll,ll>> que;
			
				que.push(make_pair(x,1));
				ll p = 1,ele = 0;
				check = true;
				visited[x] = 1;
				while(!que.empty())
					{


						pair<ll,ll> u1 = que.front();
						ll u = u1.first;
						que.pop();
						//visited[u] = 1;
						//cout << u << "  " << u1.second << "\n";
						if(p != u1.second)
							{
								//cout << " depth ";
								//p = u1.second;
								if(u1.second > 1)
								depth.pb(ele);
								ele = 0;
								p = u1.second;
								
							}
						for(auto v :edge[u])
						{
							//ll v = v1.first;
							if(visited[u] == 1 && visited[v] == 1 && color[u] == color[v])
							{
								check = false;
								break;
							}
							else if(!visited[v])
							{
								visited[v] = 1;
								p = u1.second;
								que.push(make_pair(v,p+1));
								color[v] = 1 - color[u];
								ele++;
							}
						}
						if(!check)
						break;
					}
				if(!check)
					break;

				ll e = 1 , counto = 1 , counte =  2;

				for(auto num : depth)
				{
					if(e%2 == 1)
					{
						counto *= power((ll)2,num,mod);
						counto %= mod;
					}
					else
					{
						counte *= power((ll)2,num,mod);
						counte %= mod;
					}
					e++;
				}
				finall *= (counte + counto)%mod;
				finall %= mod;
				}
				//cout << "output  " << t << " ";
				if(check)
					cout << finall << "\n";
				else
					cout << 0 << "\n";
		}

	}
