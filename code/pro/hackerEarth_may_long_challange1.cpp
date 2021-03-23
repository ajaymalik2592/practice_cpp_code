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
	    int n,k;
	    cin >> n >> k;
	   	vector <int> vec(2*n),vec1, vec2;

	   	if(k == 2)
	   	{
	   		for(int x =0; x< n ; x++)
	   		{
	   			cout << (2*(x) + 1) << " ";
	   		}
	   		cout << "\n";
	   		for(int x =0; x < n ;x++)
	   		{
	   			cout << 2* (x+1) << " ";

	   		}
	   		return 0;
	   	}

	   	if(vec[0] < vec[1])
	   		vec1.pb(1), vec2.pb(2);
	   	else
	   		vec1.pb(2), vec2.pb(1);

	   	for(int x =2; x <= n ; x++)
	   	{
	   		if(vec[x * 2 -2 ] < vec[x * 2 - 1])
	   			vec1.pb(2*x - 1), vec2.pb(2 *x);
	   		else
	   			vec1.pb(2* x), vec2.pb(2*x -1);
	   	}
	    
	    for(int x : vec1)
	    {
	        cout << x <<" ";
	    }
	    cout << "\n";
	    for(int x : vec2)
	    {
	        cout << x <<" ";
	    }
	



		return 0;
	}
