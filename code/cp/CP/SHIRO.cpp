
/* Author : Vamsi Kavala */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define PB push_back
#define ITER(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)	
#define mod 1000000007
#define MAXN 1000010
#define MP make_pair
#define INF mod

typedef pair<int,int>   PI;
typedef vector<int> VI;
typedef long long int LL;

#define OFFSET 10000

double dp[110][2*OFFSET+10];
int a[110],p[110];

int main(){

	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		FOR(i,1,n+1)
			scanf("%d",&a[i]);
		FOR(i,1,n+1)
			scanf("%d",&p[i]);
	
		//dp[i][j]=probability that on the ith level we have (j-OFFSET) flags of Abra (negative implying we have more flags of Kadabra)

		memset(dp,0,sizeof(dp));
		dp[0][OFFSET]=1.0;
		p[0]=a[0]=0;
		int total=0;
		FOR(i,1,n+1)
		{
			FOR(j,-total-a[i]+OFFSET,total+a[i]+OFFSET+1)
			{
				dp[i][j]=0;
				if(j>=a[i])
					dp[i][j]+=(p[i]/100.0)*dp[i-1][j-a[i]];
				if(j+a[i]<=2*OFFSET)
					dp[i][j]+=((100-p[i])/100.0)*dp[i-1][j+a[i]];
			}
			total+=a[i];
		}
		double ans=0.0;
		FOR(j,OFFSET,2*OFFSET+1)
			ans+=dp[n][j];
		printf("%.8lf\n",ans);
	}
	return 0;
}
