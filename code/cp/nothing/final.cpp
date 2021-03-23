#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()
#define ALL(v)   v.begin(),v.end()
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    int g = 0;
    for(int x =0; x<n/4; x++)
    {
        for(int y = 0; y<n/4; y++)
        {
           
            int i = 0;
            for(int xx = 4*x; xx<(x+1)*4; xx++)
            {
                for(int yy = 4*y; yy<(y+1)*4; yy++)
                {
                    v[xx][yy] = i + g;
                    i++;
                }
            }
            g+=16;
        }
    }
    for(int x =0; x<n; x++){
        for(int y = 0; y<n; y++)
        {
            cout << v[x][y] << " ";
        }
        cout << "\n";
    }
}