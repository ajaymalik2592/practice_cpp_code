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
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int y=0, l1 = 0, l2 = 0;
    for(int x =0;x <s2.length();x++)
    {
        for(y; y<s1.length(); y++)
    {
        if(s2[x] == s1[y]){y++;l1 ++;break;}
    }
    }
    y = s1.length() - 1;
    for(int x =0 ; x  < s2.length();x++)
    {
        for(y ;y >= 0;y--)
    {
        if(s2[x] == s1[y]){y--;l2 ++;break;}
    }
    }
    //cout << l1 << " " << l2 << endl;
    if(l1 == s2.length() && l2 == s2.length())
    cout << "GOOD STRING\n";
    else
    cout << "BAD STRING\n";
}

int main()
	{
	    int t;
	    cin >> t;
	    while(t--)
	    {
	        solve();
	    }
		return 0;
	}
