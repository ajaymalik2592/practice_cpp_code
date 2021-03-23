#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v) v.begin() , v.end()

int main()
    {
        int n;
        cin >> n;
        int f = 0, s = 0,r = 0, ma = 0;
        vector<int> v;
        int temp ; 
        cin >> temp;
        f  = 1;
        r = temp;
        for(int x = 1;x < n; x++)
        {
        	cin >> temp;
        	if(temp == r )
        		f+=1;
        	else
        	{
        		v.pb(f);
        		f= 1;
        		r = temp;
        		s++;
        	}
        }
        if(f != 0)
        	v.pb(f),s++;
     	 ma = min(v[0], v[1]);
        for(int x =1 ; x<s-1  ; x++)
        {
        	ma = max(ma , min(v[x] , v[x+1]));
        }
        cout << 2*ma;
    	return 0;
    }
