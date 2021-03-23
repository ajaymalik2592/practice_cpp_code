#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

ll power(ll a , ll b , ll d){ll re =1 ; while(b){if(b%2 == 1)re*=a, re%=d; a*=a ; a%=d ; b>>=1;} return re;}

int main()
	{
		int t;
		cin >> t;
		while(t--)
		{
			int n ,m;

			cin >> n >> m ;

			vector <int> a , b;
			a.resize(n+1);
			b.resize(n+1);
			for(int x = 1 ;x <= n ;x++)
				{
					cin >> a[x];
					b[x] = a[x];
				}
			vector < pair <int ,int> > vec , ve;
			for(int x =0 ;x < m ;x++)
			{
				int i , j ;
				char u;
				cin >> i >> u >> j;
				if(u =='>' && b[i] <= b[j])
					b[i] = b[j] +1;
				if( u =='<' && b[i] >= b[j])
					b[j] = b[i] +1;
				if(u == '>')
					vec.push_back(make_pair(i,j));
				else 
					ve.push_back(make_pair(i,j));



			}
			bool tr = true;
			for(auto s : vec )
				if(b[s.first ] <= b[s.second])
				{
					tr = false;
					break;
				}
			if(tr)
			{
				for(auto s : ve )
				if(b[s.first ] >= b[s.second])
				{
					tr = false;
					break;
				}
			}
			if(tr)
			{
				cout << "YES\n";
				if(m == 0)
					b[n]++;
				for(int x =1 ; x < n+1 ; x++)
					cout << b[x] << " ";
				cout << "\n" << flush;
			}
			else 
				cout << "NO\n" << flush;
		}

	}