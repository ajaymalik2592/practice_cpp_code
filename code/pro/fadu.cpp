#include<bits/stdc++.h>
#define assn(n,a,b) assert(n>=a && n<=b)
using namespace std;
typedef long long LL; 
LL dp[100009]={},val[100009],pre[100009];
    
int main() 
{ 
    int t; 
    cin >> t;
    while(t--) 
    {
        pre[0]=0;
        LL n,i,j; 
        cin >> n; 
        assn(n,1,100000);
        for(i=n; i>0; i--)
        {
            cin >> val[i];
            assn(val[i],0ll,1000000000ll);
        } 
        for(i=1; i<=n; i++) 
            pre[i]=pre[i-1]+val[i];
        for(int x = 0; x <= n; x++)
            cout << x << " " << pre[x] << endl;
        dp[0]=0;
        dp[1]=val[1];
        dp[2]=dp[1]+val[2];
        dp[3]=dp[2]+val[3]; 
        for(i=4; i<=n; i++)
        {
            dp[i]=max(-1ll,pre[i-1]-dp[i-1]+val[i]);
            dp[i]=max(dp[i],pre[i-2]-dp[i-2]+val[i]+val[i-1]); 
            dp[i]=max(dp[i],pre[i-3]-dp[i-3]+val[i]+val[i-1]+val[i-2]); 
            cout << "i " << i << "  " << dp[i] << " pre " << pre[i-1] <<  endl;
        }
        cout << dp[n] << endl; 
    }
    return 0; 
}
