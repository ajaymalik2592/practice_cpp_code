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
ll mod = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if(b == 0)return a;
    else return gcd(b, a%b);
}
int main()
	{
	    string a, s;
	    cin >> a >> s;
	    ll s1 = 0, n = s.length();
	    vector<int> pi(n + 1 + a.length() );
	    s  += "#" + a;
	    for (int i = 1; i < n + 1+ a.length(); i++) {
	        int j = pi[i-1];
	        while (j > 0 && s[i] != s[j])
	            j = pi[j-1];
	        if (s[i] == s[j])
	            j++;
	        pi[i] = j;
	    }
	    int p = n + 1 + a.length();
	    for(int x = n+1; x<p ; x++ )
	    	cout << x << " " << pi[x] << endl;
	    int h = 0;
	    for(int x = 0; x<n ; x++)
	    	if(s[x] == a[x])h ++;
	    if((n-h)%2 == 0)s1++;
	   
	    for(int x = 2*n+1; x< n + 1 + a.length(); x++)
	    {
	    	int j = pi[x];
	    	h = j;
	    	if(s[x] == s[j])
	    		h ++;

	    	int f = x + n - h;
	    	if(f > p )
	    		break;
	    	for(;j < n; x++, j++)
	    	{
	    		if(s[x] == s[j])h++;

	    	}
	    	if((n-h)%2 == 0)s1++;
	    	x--;
	    }
	    cout << s1;


		
	}