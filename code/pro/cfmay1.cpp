#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
int main()
	{
		int n, k;
		cin >> n >> k;
		string s = "";
		if( n  & 1)
		{
			if( n== k)
			{
				for(int x =0; x <n; x++)
				{
					s+="1";
				}

			}
			else
			{
				
				for(int x =0; x < k; x++)
				{
					if(x &1)
						s += "0";
					else
						s+= "1";
				}

				for( int x = 0; x < (n-k)/2; x++)
					s+="0", s = "0"+ s; 
			}
		}
		else
		{
			if( n== k)
			{
				for(int x =0; x <n; x++)
				{
					s+= "1";
				}

			}
			else
			{
				
				for(int x =0; x < k; x++)
				{
					if(x &1)
						s += "0";
					else
						s+= "1";
				}

				for( int x =  0; x < (n-k)/2; x++)
					{
						if( x % 2 == 0)
						{
							s = "0" +  s;
							s = s + "1"; 
						}
						else
						{
							s = "1" +  s;
							s = s + "0"; 
						}
					}
			}
		}
		
		cout << s ;


	}
