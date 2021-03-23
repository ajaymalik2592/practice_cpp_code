#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(int i = a ; i <=b ; i++)
#define R(i,a,b) for(int i = a ; i >= b ; i--)
#define pb push_back
#define speed ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ub(a,x) upper_bound(a.begin(),a.end(),x)-a.begin()
#define lb(a,x) lower_bound(a.begin(),a.end(),x)-a.begin()

int main()
	{

		speed
		int n , k , m;
		cin >> n >> k >> m;
		int a[n];
		long double su = 0 ;int  index  =0;
		F(x,0,n-1)cin>>a[x]  , su += a[x];

		sort(a , a + n);
		//reverse(a , a+ n);

		/*for(int x = 1 ;x< n ;x++)
			{
				if(a[x]  == a[0] && m > index )index++;
				else break;
			}
			*/
		 long double y = 0;
		 int n1 = n;
		for(int x = 0 ;x < m ;x++)
		{
			if(index == n-1 )
				{
					y+=m-x;
					break;
				}
			if(( (su + min(y ,(long double )k * n1)   + 1) / n1  > (su + min(y , (long double)k *(n1 - 1) ) - a[index])/(n1-1 )) && y/n1 <=  k ) y++ ;
			else n1--  , su -= a[index] , index++;
		}
		n = n1;
		cout<<fixed;
		if( y/n <= k){
			cout<<setprecision(15)<<(su + y )/ n;
		}
		else cout<<setprecision(15)<< su/n + k;
		cout<<"\n";


		return 0;
	}