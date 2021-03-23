#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    int t;
    cin >> t;
    string s1 , s2;
    cin  >> s1 >> s2;
    vector <int> both ,non , acro , clone;
    int a = 0 , n =0 , b =0, c =0;
    for(int x = 0;x <t;x++)
    {
        if(s1[x] == '0' && s2[x] == '0')
            n++ ,non.pb(x+1); 
        else if(s1[x] == '0' && s2[x] == '1')
            c++ ,clone.pb(x+1); 
        else if(s1[x] == '1' && s2[x] == '0')
            a++ ,acro.pb(x+1); 
        else
            b++ ,both.pb(x+1); 

    }   
    int i1 = 0, i2 = 0, i3 = 0,i4=0;
    vector <int > fi , se;
    for(int x =0;x <min(a,c);x++)
    {
        fi.pb(a[x]);
        se.pb(c[x]);
        i2 = i3 = x+1;
    }
    for(int x =i2; x < n/2 && max(a,c) - min(a,c)  ;x++ )
    {

    }

    return 0;
}