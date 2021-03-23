#include<bits/stdc++.h>
using namespace std;
typedef long long
#define speed ios_bse::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
	speed
    int t;
    cin >> t;
    while(t--)
    {
        string s, s1 = "", s2 = "";
        cin >> s;
        
        for(auto f : s)
        {
            if(f == '4')
            {
                s1 += "2";
                s2 += "2";
            }
            else
            {
                s1 += f;
                s2 += "0";
            }
        }
        int d= 0;
        for(auto f : s2)
        {
            if(f != '0')
            {
                
                break;
            }
            d ++;
        }
        string g= "";
        for(int x =d; x < s2.length(); x++)g += s2[d];
        cout << s1 << " " << g << "\n";
    }
}
