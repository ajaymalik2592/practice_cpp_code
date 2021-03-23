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
	    speed
	    int q;
	    cin >> q;
	    int m = 0;
	   	vector <int> vec = {0};

	    while(q--)
	    {
	        int i,j;
	        cin >> i;
	        if( i == 1)
	        {
	            cin >> j ;
	            m = min(j, m);
	            vec.pb(j);
	        }
	        else if(i == 2)
	        {
	            cin >> j;
	            m = 2000000000;
	            for(auto &h : vec)
	            {
	            	h = h ^ j;
	            	m= min(h, m);
	            }
	        }
	        else
	        cout << m << "\n";
	    }
		return 0;
	}
