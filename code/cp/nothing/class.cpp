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
       map<int,int> ma[100];
       ma[2][2] = 1;
       ma[4] = ma[4/2];
       ma[4][2]++;
      for(auto s : ma[4])cout << s.first << " " << s.second << endl;
    
        return 0;
    }
