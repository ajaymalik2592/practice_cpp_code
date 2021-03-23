#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mx 5005
#define mx2 129
#define mod 1000000007
#define inf 1e18
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
inline int add(int x,int y)
{
if(x + y >= mod)
return x + y - mod;
return x + y;
}
inline int sub(int x,int y)
{
if(x - y < 0)
return x - y + mod;
return x - y;
}
inline int mul(int x,int y)
{
return 1LL * x * y % mod;
}

int n,c;
bool type[mx];
vector<int> v[mx];
int level[mx];
int dp[mx];
void dfs(int x,int p, int org)
{
ll ans = 1;
for(auto i : v[x])
{
if(i == p)
continue;
if(level[i] < level[org] || level[i] == level[org] && i < org || level[i] - level[org] > c)
{
continue;
}
dfs(i,x,org);
ans = mul(ans, dp[i] + 1);
}
dp[x] = ans;
}
void dfs1(int x,int p, int org)
{
ll ans = 1;
for(auto i : v[x])
{
if(i == p)
continue;
if(level[i] < level[org] || level[i] == level[org] && i < org || level[i] - level[org] > c)
{
continue;
}
if(type[i] != type[org])
continue;
dfs1(i,x,org);
ans = mul(ans, dp[i] + 1);
}
dp[x] = ans;
}
main()
{

cin >> n >> c;
c--;
fl(i,1,n+1)
{
cin >> type[i];
}
fl(i,1,n+1)
{
cin >> level[i];
}
fl(i,1,n)
{
int x,y;
cin >> x >> y;
v[x].pb(y);
v[y].pb(x);
}
ll ans = 0;
fl(i,1,n+1)
{
fl(j,1,n+1)
{
dp[j] = 0;
}
dfs(i,0,i);
ans = add(ans,dp[i]);
fl(j,1,n+1)
{
dp[j] = 0;
}
dfs1(i,0,i);
ans = sub(ans,dp[i]);
}
cout<<ans;
}